#! /usr/bin/env node
const fs = require("fs").promises;

const pokespriteDir = "../../../pokesprite";
const spriteDir = "../../romfs/pokemon-sprites_";

const spriteData = require(`${pokespriteDir}/data/pokemon.json`);

function getSourcesAndTargets(pokemonData) {
    const {idx, slug: {eng: psname}, "gen-8": {forms}} = pokemonData;
    const normalizeFormName = formName => ["$", "female"].includes(formName)? "" : `-${formName}`;
    const normalizeFormId = id => id === 0 ? "" : `-${id}`;

    const makeSrcTgt = (form, i, isShiny) => [
        `${pokespriteDir}/pokemon-gen8/${isShiny ? "shiny" : "regular"}/${
            form === "female" ? "female/" : ""}${psname}${normalizeFormName(form)}.png`,
        `${spriteDir}/b_${idx.replace(/^0+/, "")}${form === "gmax" ? "g" : normalizeFormId(i)}${isShiny? "s" : ""}.png`
    ];

    // I think this is an inconsistency in the pokesprite data structure
    if (forms["$"].has_female) {
        forms.female = {};
    }

    return Object.entries(forms)
        // remove unnecessary and unavailable sprites
        .filter(([_, fv]) => (!fv.is_alias_of))
        // convert to paths along with adding shinies
        .flatMap(([form, _], i) => [
            makeSrcTgt(form, i, false),
            makeSrcTgt(form, i, true)            
        ]);
}

Promise.all(
    Object.values(spriteData)
        .flatMap(getSourcesAndTargets)
        .map(args => fs.copyFile(...args))
);

// runtime: 14 seconds
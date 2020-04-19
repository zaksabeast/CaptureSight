#! /usr/bin/env python3
import json
import re
from shutil import copyfile

pokesprite_dir = "../../../pokesprite"
sprite_dir = "../../romfs/pokemon-sprites_"

# this does NOT preserve the order of entries
# and therefore will not always identify the base form as the 0-th entry
sprite_data = json.load(open("{}/data/pokemon.json".format(pokesprite_dir)))

def src_str(pokemon, form, is_shiny):
    return\
        pokesprite_dir + "/pokemon-gen8" +\
        ("/shiny/" if is_shiny else "/regular/") +\
        ("female/" if form == "female" else "") +\
        pokemon["slug"]["eng"] +\
        ("" if form in ["$", "female"] else "-{}".format(form)) + ".png"

def dest_str(pokemon, form, form_i, is_shiny):
    return\
        sprite_dir + "/" +\
        re.sub(r"^0+", "", pokemon["idx"]) +\
        ("g" if form == "gmax" else ("" if form_i == 0 else "-{}".format(form_i))) +\
        ("s" if is_shiny else "") + ".png"

for _, pokemon in sprite_data.items():
    if "has_female" in pokemon["gen-8"]["forms"]["$"] and\
        pokemon["gen-8"]["forms"]["$"]["has_female"]:
        pokemon["gen-8"]["forms"]["female"] = {}
    
    for fi, (form, data) in enumerate(pokemon["gen-8"]["forms"].items()):
        if "is_alias_of" in data and data["is_alias_of"]:
            continue
        
        src_n = src_str(pokemon, form, False)
        src_s = src_str(pokemon, form, True)
        dst_n = dest_str(pokemon, form, fi, False)
        dst_s = dest_str(pokemon, form, fi, True)

        copyfile(src_n, dst_n)
        copyfile(src_s, dst_s)

# runtime: 18 seconds
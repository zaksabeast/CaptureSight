use super::{
    den_encounter::{DenEncounter, DenEncounters},
    den_hashes::Nest,
};
use pkm_rs::types;

#[rustfmt::skip]
const NEST_17428356DC6109F6: DenEncounters = [
  DenEncounter { species: types::Species::Tyrogue, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Machop, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Timburr, flawless_ivs: 1, probabilities: [20, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Scraggy, flawless_ivs: 1, probabilities: [10, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Machoke, flawless_ivs: 2, probabilities: [0, 20, 10, 0, 0] },
  DenEncounter { species: types::Species::Gurdurr, flawless_ivs: 2, probabilities: [0, 20, 30, 0, 0] },
  DenEncounter { species: types::Species::Hitmonlee, flawless_ivs: 3, probabilities: [0, 0, 20, 25, 0] },
  DenEncounter { species: types::Species::Hitmonchan, flawless_ivs: 4, probabilities: [0, 0, 20, 25, 30] },
  DenEncounter { species: types::Species::Scrafty, flawless_ivs: 4, probabilities: [0, 0, 20, 25, 30] },
  DenEncounter { species: types::Species::Conkeldurr, flawless_ivs: 4, probabilities: [0, 0, 0, 25, 20] },
  DenEncounter { species: types::Species::Machamp, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 10] },
  DenEncounter { species: types::Species::Hitmontop, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 10] },
];

#[rustfmt::skip]
const NEST_17428256DC610843: DenEncounters = [
  DenEncounter { species: types::Species::Ralts, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Munna, flawless_ivs: 1, probabilities: [30, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Espurr, flawless_ivs: 1, probabilities: [20, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Gothita, flawless_ivs: 1, probabilities: [10, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Elgyem, flawless_ivs: 1, probabilities: [5, 20, 0, 0, 0] },
  DenEncounter { species: types::Species::Kirlia, flawless_ivs: 2, probabilities: [0, 20, 40, 0, 0] },
  DenEncounter { species: types::Species::Meowstic, flawless_ivs: 3, probabilities: [0, 0, 20, 30, 0] },
  DenEncounter { species: types::Species::Gothorita, flawless_ivs: 3, probabilities: [0, 0, 20, 30, 0] },
  DenEncounter { species: types::Species::Musharna, flawless_ivs: 4, probabilities: [0, 0, 20, 30, 25] },
  DenEncounter { species: types::Species::Gothitelle, flawless_ivs: 4, probabilities: [0, 0, 0, 10, 25] },
  DenEncounter { species: types::Species::Solrock, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 25] },
  DenEncounter { species: types::Species::Gardevoir, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 25] },
];

#[rustfmt::skip]
const NEST_17428156DC610690: DenEncounters = [
  DenEncounter { species: types::Species::Bonsly, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Roggenrola, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Binacle, flawless_ivs: 1, probabilities: [20, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Dwebble, flawless_ivs: 1, probabilities: [10, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Rhyhorn, flawless_ivs: 2, probabilities: [0, 20, 10, 0, 0] },
  DenEncounter { species: types::Species::Boldore, flawless_ivs: 2, probabilities: [0, 20, 30, 0, 0] },
  DenEncounter { species: types::Species::Barbaracle, flawless_ivs: 3, probabilities: [0, 0, 20, 10, 0] },
  DenEncounter { species: types::Species::Rhydon, flawless_ivs: 4, probabilities: [0, 0, 20, 20, 10] },
  DenEncounter { species: types::Species::Sudowoodo, flawless_ivs: 4, probabilities: [0, 0, 20, 20, 25] },
  DenEncounter { species: types::Species::Crustle, flawless_ivs: 4, probabilities: [0, 0, 0, 50, 25] },
  DenEncounter { species: types::Species::Gigalith, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 20] },
  DenEncounter { species: types::Species::Shuckle, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 20] },
];

#[rustfmt::skip]
const NEST_17428856DC611275: DenEncounters = [
  DenEncounter { species: types::Species::Caterpie, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Grubbin, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Nincada, flawless_ivs: 1, probabilities: [20, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Joltik, flawless_ivs: 1, probabilities: [10, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Metapod, flawless_ivs: 2, probabilities: [0, 20, 10, 0, 0] },
  DenEncounter { species: types::Species::Durant, flawless_ivs: 2, probabilities: [0, 20, 30, 0, 0] },
  DenEncounter { species: types::Species::Charjabug, flawless_ivs: 3, probabilities: [0, 0, 20, 10, 0] },
  DenEncounter { species: types::Species::Ninjask, flawless_ivs: 4, probabilities: [0, 0, 20, 20, 10] },
  DenEncounter { species: types::Species::Butterfree, flawless_ivs: 4, probabilities: [0, 0, 20, 20, 25] },
  DenEncounter { species: types::Species::Galvantula, flawless_ivs: 4, probabilities: [0, 0, 0, 50, 25] },
  DenEncounter { species: types::Species::Vikavolt, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 20] },
  DenEncounter { species: types::Species::Durant, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 20] },
];

#[rustfmt::skip]
const NEST_17428756DC6110C2: DenEncounters = [
  DenEncounter { species: types::Species::Caterpie, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Combee, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Cutiefly, flawless_ivs: 1, probabilities: [20, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Blipbug, flawless_ivs: 1, probabilities: [10, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Joltik, flawless_ivs: 2, probabilities: [0, 20, 10, 0, 0] },
  DenEncounter { species: types::Species::Metapod, flawless_ivs: 2, probabilities: [0, 20, 30, 0, 0] },
  DenEncounter { species: types::Species::Dottler, flawless_ivs: 3, probabilities: [0, 0, 20, 10, 0] },
  DenEncounter { species: types::Species::Galvantula, flawless_ivs: 4, probabilities: [0, 0, 20, 20, 10] },
  DenEncounter { species: types::Species::Butterfree, flawless_ivs: 4, probabilities: [0, 0, 20, 20, 25] },
  DenEncounter { species: types::Species::Ribombee, flawless_ivs: 4, probabilities: [0, 0, 0, 50, 25] },
  DenEncounter { species: types::Species::Vespiquen, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 20] },
  DenEncounter { species: types::Species::Orbeetle, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 20] },
];

#[rustfmt::skip]
const NEST_17428656DC610F0F: DenEncounters = [
  DenEncounter { species: types::Species::Gastly, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Duskull, flawless_ivs: 1, probabilities: [30, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Drifloon, flawless_ivs: 1, probabilities: [20, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Phantump, flawless_ivs: 1, probabilities: [10, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Frillish, flawless_ivs: 1, probabilities: [5, 20, 0, 0, 0] },
  DenEncounter { species: types::Species::Pumpkaboo, flawless_ivs: 2, probabilities: [0, 20, 40, 0, 0] },
  DenEncounter { species: types::Species::Haunter, flawless_ivs: 3, probabilities: [0, 0, 20, 10, 0] },
  DenEncounter { species: types::Species::Dusclops, flawless_ivs: 4, probabilities: [0, 0, 20, 20, 10] },
  DenEncounter { species: types::Species::Drifblim, flawless_ivs: 4, probabilities: [0, 0, 20, 20, 25] },
  DenEncounter { species: types::Species::Trevenant, flawless_ivs: 4, probabilities: [0, 0, 0, 50, 25] },
  DenEncounter { species: types::Species::Gourgeist, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 20] },
  DenEncounter { species: types::Species::Jellicent, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 20] },
];

#[rustfmt::skip]
const NEST_17428556DC610D5C: DenEncounters = [
  DenEncounter { species: types::Species::Magikarp, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Mantyke, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Remoraid, flawless_ivs: 1, probabilities: [20, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Chinchou, flawless_ivs: 1, probabilities: [10, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Wailmer, flawless_ivs: 2, probabilities: [0, 20, 10, 0, 0] },
  DenEncounter { species: types::Species::Basculin, flawless_ivs: 2, probabilities: [0, 20, 30, 0, 0] },
  DenEncounter { species: types::Species::Octillery, flawless_ivs: 3, probabilities: [0, 0, 20, 10, 0] },
  DenEncounter { species: types::Species::Mantine, flawless_ivs: 4, probabilities: [0, 0, 20, 20, 10] },
  DenEncounter { species: types::Species::Lanturn, flawless_ivs: 4, probabilities: [0, 0, 20, 20, 25] },
  DenEncounter { species: types::Species::Wailord, flawless_ivs: 4, probabilities: [0, 0, 0, 50, 25] },
  DenEncounter { species: types::Species::Wishiwashi, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 20] },
  DenEncounter { species: types::Species::Gyarados, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 20] },
];

#[rustfmt::skip]
const NEST_17428C56DC611941: DenEncounters = [
  DenEncounter { species: types::Species::Chewtle, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Arrokuda, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Shellos, flawless_ivs: 1, probabilities: [20, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Dewpider, flawless_ivs: 1, probabilities: [10, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Wailmer, flawless_ivs: 2, probabilities: [0, 20, 10, 0, 0] },
  DenEncounter { species: types::Species::Basculin, flawless_ivs: 2, probabilities: [0, 20, 30, 0, 0] },
  DenEncounter { species: types::Species::Wishiwashi, flawless_ivs: 3, probabilities: [0, 0, 20, 10, 0] },
  DenEncounter { species: types::Species::Drednaw, flawless_ivs: 4, probabilities: [0, 0, 20, 20, 10] },
  DenEncounter { species: types::Species::Barraskewda, flawless_ivs: 4, probabilities: [0, 0, 20, 20, 25] },
  DenEncounter { species: types::Species::Araquanid, flawless_ivs: 4, probabilities: [0, 0, 0, 50, 25] },
  DenEncounter { species: types::Species::Gastrodon, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 20] },
  DenEncounter { species: types::Species::Wailord, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 20] },
];

#[rustfmt::skip]
const NEST_17428B56DC61178E: DenEncounters = [
  DenEncounter { species: types::Species::Chewtle, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Wooper, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Tympole, flawless_ivs: 1, probabilities: [20, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Corphish, flawless_ivs: 1, probabilities: [10, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Shellder, flawless_ivs: 2, probabilities: [0, 20, 0, 0, 0] },
  DenEncounter { species: types::Species::Palpitoad, flawless_ivs: 2, probabilities: [0, 20, 40, 0, 0] },
  DenEncounter { species: types::Species::Drednaw, flawless_ivs: 3, probabilities: [0, 0, 20, 10, 0] },
  DenEncounter { species: types::Species::Quagsire, flawless_ivs: 4, probabilities: [0, 0, 20, 20, 10] },
  DenEncounter { species: types::Species::Pyukumuku, flawless_ivs: 4, probabilities: [0, 0, 20, 20, 25] },
  DenEncounter { species: types::Species::Cloyster, flawless_ivs: 4, probabilities: [0, 0, 0, 50, 25] },
  DenEncounter { species: types::Species::Seismitoad, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 20] },
  DenEncounter { species: types::Species::Crawdaunt, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 20] },
];

#[rustfmt::skip]
const NEST_173EFE56DC5DF220: DenEncounters = [
  DenEncounter { species: types::Species::Tyrogue, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Stufful, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Clobbopus, flawless_ivs: 1, probabilities: [20, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Pancham, flawless_ivs: 1, probabilities: [10, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::FarfetchD, flawless_ivs: 2, probabilities: [0, 20, 0, 0, 0] },
  DenEncounter { species: types::Species::Sawk, flawless_ivs: 2, probabilities: [0, 20, 40, 0, 0] },
  DenEncounter { species: types::Species::Bewear, flawless_ivs: 4, probabilities: [0, 0, 20, 33, 22] },
  DenEncounter { species: types::Species::Pangoro, flawless_ivs: 4, probabilities: [0, 0, 20, 33, 22] },
  DenEncounter { species: types::Species::Hawlucha, flawless_ivs: 4, probabilities: [0, 0, 20, 33, 20] },
  DenEncounter { species: types::Species::SirfetchD, flawless_ivs: 4, probabilities: [0, 0, 0, 1, 1] },
  DenEncounter { species: types::Species::Grapploct, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 25] },
  DenEncounter { species: types::Species::Falinks, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 10] },
];

#[rustfmt::skip]
const NEST_173EFF56DC5DF3D3: DenEncounters = [
  DenEncounter { species: types::Species::Klink, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Meowth, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Bronzor, flawless_ivs: 1, probabilities: [20, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Ferroseed, flawless_ivs: 1, probabilities: [10, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Pawniard, flawless_ivs: 2, probabilities: [0, 20, 0, 0, 0] },
  DenEncounter { species: types::Species::Cufant, flawless_ivs: 2, probabilities: [0, 20, 40, 0, 0] },
  DenEncounter { species: types::Species::Klang, flawless_ivs: 4, probabilities: [0, 0, 20, 25, 10] },
  DenEncounter { species: types::Species::Perrserker, flawless_ivs: 4, probabilities: [0, 0, 20, 25, 10] },
  DenEncounter { species: types::Species::Bronzong, flawless_ivs: 4, probabilities: [0, 0, 20, 25, 30] },
  DenEncounter { species: types::Species::Bisharp, flawless_ivs: 4, probabilities: [0, 0, 0, 25, 30] },
  DenEncounter { species: types::Species::Klinklang, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 10] },
  DenEncounter { species: types::Species::Copperajah, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 10] },
];

#[rustfmt::skip]
const NEST_173F0056DC5DF586: DenEncounters = [
  DenEncounter { species: types::Species::Klink, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Bronzor, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Ferroseed, flawless_ivs: 1, probabilities: [20, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Pawniard, flawless_ivs: 1, probabilities: [10, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Klink, flawless_ivs: 2, probabilities: [0, 20, 0, 0, 0] },
  DenEncounter { species: types::Species::Bronzor, flawless_ivs: 2, probabilities: [0, 20, 40, 0, 0] },
  DenEncounter { species: types::Species::Steelix, flawless_ivs: 4, probabilities: [0, 0, 20, 25, 10] },
  DenEncounter { species: types::Species::Ferrothorn, flawless_ivs: 4, probabilities: [0, 0, 20, 25, 10] },
  DenEncounter { species: types::Species::Bronzong, flawless_ivs: 4, probabilities: [0, 0, 20, 25, 30] },
  DenEncounter { species: types::Species::Bisharp, flawless_ivs: 4, probabilities: [0, 0, 0, 25, 30] },
  DenEncounter { species: types::Species::Mawile, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 10] },
  DenEncounter { species: types::Species::Togedemaru, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 10] },
];

#[rustfmt::skip]
const NEST_173F0156DC5DF739: DenEncounters = [
  DenEncounter { species: types::Species::MimeJr, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Blipbug, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Natu, flawless_ivs: 1, probabilities: [20, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Hatenna, flawless_ivs: 1, probabilities: [10, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Dottler, flawless_ivs: 2, probabilities: [0, 20, 0, 0, 0] },
  DenEncounter { species: types::Species::Hattrem, flawless_ivs: 2, probabilities: [0, 20, 40, 15, 0] },
  DenEncounter { species: types::Species::Sigilyph, flawless_ivs: 3, probabilities: [0, 0, 20, 25, 0] },
  DenEncounter { species: types::Species::Xatu, flawless_ivs: 3, probabilities: [0, 0, 20, 25, 0] },
  DenEncounter { species: types::Species::Indeedee, flawless_ivs: 4, probabilities: [0, 0, 20, 25, 25] },
  DenEncounter { species: types::Species::Sigilyph, flawless_ivs: 4, probabilities: [0, 0, 0, 10, 25] },
  DenEncounter { species: types::Species::Orbeetle, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 25] },
  DenEncounter { species: types::Species::Hatterene, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 25] },
];

#[rustfmt::skip]
const NEST_173F0256DC5DF8EC: DenEncounters = [
  DenEncounter { species: types::Species::MimeJr, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Wynaut, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Natu, flawless_ivs: 1, probabilities: [20, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Baltoy, flawless_ivs: 1, probabilities: [10, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Bronzor, flawless_ivs: 1, probabilities: [0, 20, 0, 0, 0] },
  DenEncounter { species: types::Species::MrMime, flawless_ivs: 3, probabilities: [0, 20, 40, 15, 0] },
  DenEncounter { species: types::Species::Sigilyph, flawless_ivs: 3, probabilities: [0, 0, 20, 25, 0] },
  DenEncounter { species: types::Species::Xatu, flawless_ivs: 3, probabilities: [0, 0, 20, 25, 0] },
  DenEncounter { species: types::Species::Indeedee, flawless_ivs: 4, probabilities: [0, 0, 20, 25, 25] },
  DenEncounter { species: types::Species::Claydol, flawless_ivs: 4, probabilities: [0, 0, 0, 10, 25] },
  DenEncounter { species: types::Species::MrRime, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 25] },
  DenEncounter { species: types::Species::Wobbuffet, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 25] },
];

#[rustfmt::skip]
const NEST_173F0356DC5DFA9F: DenEncounters = [
  DenEncounter { species: types::Species::Rolycoly, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Roggenrola, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Dwebble, flawless_ivs: 1, probabilities: [20, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Binacle, flawless_ivs: 1, probabilities: [10, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Carkol, flawless_ivs: 1, probabilities: [0, 20, 0, 0, 0] },
  DenEncounter { species: types::Species::Boldore, flawless_ivs: 2, probabilities: [0, 20, 40, 0, 0] },
  DenEncounter { species: types::Species::Crustle, flawless_ivs: 3, probabilities: [0, 0, 20, 10, 0] },
  DenEncounter { species: types::Species::Barbaracle, flawless_ivs: 4, probabilities: [0, 0, 20, 20, 15] },
  DenEncounter { species: types::Species::Onix, flawless_ivs: 4, probabilities: [0, 0, 20, 20, 25] },
  DenEncounter { species: types::Species::Coalossal, flawless_ivs: 4, probabilities: [0, 0, 0, 50, 25] },
  DenEncounter { species: types::Species::Gigalith, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 30] },
  DenEncounter { species: types::Species::Rhyperior, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 5] },
];

#[rustfmt::skip]
const NEST_173F0456DC5DFC52: DenEncounters = [
  DenEncounter { species: types::Species::Diglett, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Mudbray, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Nincada, flawless_ivs: 1, probabilities: [20, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Drilbur, flawless_ivs: 1, probabilities: [10, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Onix, flawless_ivs: 1, probabilities: [0, 20, 0, 0, 0] },
  DenEncounter { species: types::Species::Barboach, flawless_ivs: 2, probabilities: [0, 20, 40, 0, 0] },
  DenEncounter { species: types::Species::Steelix, flawless_ivs: 3, probabilities: [0, 0, 20, 10, 0] },
  DenEncounter { species: types::Species::Whiscash, flawless_ivs: 4, probabilities: [0, 0, 20, 20, 10] },
  DenEncounter { species: types::Species::Diggersby, flawless_ivs: 4, probabilities: [0, 0, 20, 20, 25] },
  DenEncounter { species: types::Species::Dugtrio, flawless_ivs: 4, probabilities: [0, 0, 0, 50, 25] },
  DenEncounter { species: types::Species::Excadrill, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 30] },
  DenEncounter { species: types::Species::Mudsdale, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 10] },
];

#[rustfmt::skip]
const NEST_173F0556DC5DFE05: DenEncounters = [
  DenEncounter { species: types::Species::Silicobra, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Yamask, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Hippopotas, flawless_ivs: 1, probabilities: [20, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Swinub, flawless_ivs: 1, probabilities: [10, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Trapinch, flawless_ivs: 1, probabilities: [0, 20, 0, 0, 0] },
  DenEncounter { species: types::Species::Piloswine, flawless_ivs: 2, probabilities: [0, 20, 40, 0, 0] },
  DenEncounter { species: types::Species::Vibrava, flawless_ivs: 3, probabilities: [0, 0, 30, 20, 0] },
  DenEncounter { species: types::Species::Stunfisk, flawless_ivs: 4, probabilities: [0, 0, 30, 30, 29] },
  DenEncounter { species: types::Species::Runerigus, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 1] },
  DenEncounter { species: types::Species::Hippowdon, flawless_ivs: 4, probabilities: [0, 0, 0, 50, 25] },
  DenEncounter { species: types::Species::Flygon, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 35] },
  DenEncounter { species: types::Species::Sandaconda, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 10] },
];

#[rustfmt::skip]
const NEST_173F0656DC5DFFB8: DenEncounters = [
  DenEncounter { species: types::Species::Vulpix, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Sizzlipede, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Salandit, flawless_ivs: 1, probabilities: [20, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Litwick, flawless_ivs: 1, probabilities: [10, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Darumaka, flawless_ivs: 1, probabilities: [0, 20, 0, 0, 0] },
  DenEncounter { species: types::Species::Salazzle, flawless_ivs: 2, probabilities: [0, 20, 40, 0, 0] },
  DenEncounter { species: types::Species::Lampent, flawless_ivs: 3, probabilities: [0, 0, 20, 10, 0] },
  DenEncounter { species: types::Species::Ninetales, flawless_ivs: 4, probabilities: [0, 0, 20, 20, 10] },
  DenEncounter { species: types::Species::Torkoal, flawless_ivs: 4, probabilities: [0, 0, 20, 20, 25] },
  DenEncounter { species: types::Species::Centiskorch, flawless_ivs: 4, probabilities: [0, 0, 0, 50, 25] },
  DenEncounter { species: types::Species::Heatmor, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 30] },
  DenEncounter { species: types::Species::Darmanitan, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 10] },
];

#[rustfmt::skip]
const NEST_173F0756DC5E016B: DenEncounters = [
  DenEncounter { species: types::Species::Vulpix, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Salandit, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Litwick, flawless_ivs: 1, probabilities: [20, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Vulpix, flawless_ivs: 1, probabilities: [10, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Salandit, flawless_ivs: 1, probabilities: [0, 20, 0, 0, 0] },
  DenEncounter { species: types::Species::Salazzle, flawless_ivs: 2, probabilities: [0, 20, 40, 0, 0] },
  DenEncounter { species: types::Species::Lampent, flawless_ivs: 3, probabilities: [0, 0, 20, 35, 0] },
  DenEncounter { species: types::Species::Ninetales, flawless_ivs: 4, probabilities: [0, 0, 20, 25, 30] },
  DenEncounter { species: types::Species::Torkoal, flawless_ivs: 4, probabilities: [0, 0, 20, 25, 30] },
  DenEncounter { species: types::Species::Salazzle, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Chandelure, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Turtonator, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 5] },
];

#[rustfmt::skip]
const NEST_17491056DC66653B: DenEncounters = [
  DenEncounter { species: types::Species::Vulpix, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Sizzlipede, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Salandit, flawless_ivs: 1, probabilities: [20, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Litwick, flawless_ivs: 1, probabilities: [10, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Darumaka, flawless_ivs: 1, probabilities: [0, 20, 0, 0, 0] },
  DenEncounter { species: types::Species::Salazzle, flawless_ivs: 2, probabilities: [0, 20, 40, 0, 0] },
  DenEncounter { species: types::Species::Carkol, flawless_ivs: 3, probabilities: [0, 0, 20, 10, 0] },
  DenEncounter { species: types::Species::Ninetales, flawless_ivs: 4, probabilities: [0, 0, 20, 20, 10] },
  DenEncounter { species: types::Species::Torkoal, flawless_ivs: 4, probabilities: [0, 0, 20, 20, 25] },
  DenEncounter { species: types::Species::Centiskorch, flawless_ivs: 4, probabilities: [0, 0, 0, 50, 25] },
  DenEncounter { species: types::Species::Coalossal, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 30] },
  DenEncounter { species: types::Species::Darmanitan, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 10] },
];

#[rustfmt::skip]
const NEST_17490F56DC666388: DenEncounters = [
  DenEncounter { species: types::Species::Vanillite, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Swinub, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Snover, flawless_ivs: 1, probabilities: [20, 35, 0, 0, 0] },
  DenEncounter { species: types::Species::Bergmite, flawless_ivs: 1, probabilities: [10, 35, 0, 0, 0] },
  DenEncounter { species: types::Species::Delibird, flawless_ivs: 1, probabilities: [0, 5, 0, 0, 0] },
  DenEncounter { species: types::Species::Vanillish, flawless_ivs: 2, probabilities: [0, 25, 40, 0, 0] },
  DenEncounter { species: types::Species::Piloswine, flawless_ivs: 3, probabilities: [0, 0, 20, 10, 0] },
  DenEncounter { species: types::Species::Avalugg, flawless_ivs: 4, probabilities: [0, 0, 20, 20, 10] },
  DenEncounter { species: types::Species::Abomasnow, flawless_ivs: 4, probabilities: [0, 0, 20, 20, 25] },
  DenEncounter { species: types::Species::Cloyster, flawless_ivs: 4, probabilities: [0, 0, 0, 50, 25] },
  DenEncounter { species: types::Species::Vanilluxe, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 30] },
  DenEncounter { species: types::Species::Lapras, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 10] },
];

#[rustfmt::skip]
const NEST_17491256DC6668A1: DenEncounters = [
  DenEncounter { species: types::Species::Swinub, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Cubchoo, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Snom, flawless_ivs: 1, probabilities: [20, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Sneasel, flawless_ivs: 1, probabilities: [10, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::MrMime, flawless_ivs: 1, probabilities: [0, 20, 0, 0, 0] },
  DenEncounter { species: types::Species::Piloswine, flawless_ivs: 2, probabilities: [0, 20, 40, 0, 0] },
  DenEncounter { species: types::Species::Cloyster, flawless_ivs: 3, probabilities: [0, 0, 20, 35, 0] },
  DenEncounter { species: types::Species::Beartic, flawless_ivs: 4, probabilities: [0, 0, 20, 25, 10] },
  DenEncounter { species: types::Species::MrRime, flawless_ivs: 4, probabilities: [0, 0, 20, 25, 30] },
  DenEncounter { species: types::Species::Mamoswine, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 30] },
  DenEncounter { species: types::Species::Frosmoth, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 20] },
  DenEncounter { species: types::Species::Weavile, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 10] },
];

#[rustfmt::skip]
const NEST_17491156DC6666EE: DenEncounters = [
  DenEncounter { species: types::Species::Snorunt, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Snom, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Darumaka, flawless_ivs: 1, probabilities: [20, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Sneasel, flawless_ivs: 1, probabilities: [10, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::MrMime, flawless_ivs: 2, probabilities: [0, 20, 0, 0, 0] },
  DenEncounter { species: types::Species::Snover, flawless_ivs: 3, probabilities: [0, 20, 40, 0, 0] },
  DenEncounter { species: types::Species::Abomasnow, flawless_ivs: 3, probabilities: [0, 0, 20, 35, 0] },
  DenEncounter { species: types::Species::Glalie, flawless_ivs: 4, probabilities: [0, 0, 20, 25, 20] },
  DenEncounter { species: types::Species::MrRime, flawless_ivs: 4, probabilities: [0, 0, 20, 25, 30] },
  DenEncounter { species: types::Species::Frosmoth, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 30] },
  DenEncounter { species: types::Species::Froslass, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 10] },
  DenEncounter { species: types::Species::Darmanitan, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 10] },
];

#[rustfmt::skip]
const NEST_17491456DC666C07: DenEncounters = [
  DenEncounter { species: types::Species::Pichu, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Electrike, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Joltik, flawless_ivs: 1, probabilities: [20, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Chinchou, flawless_ivs: 1, probabilities: [10, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Charjabug, flawless_ivs: 2, probabilities: [0, 20, 0, 0, 0] },
  DenEncounter { species: types::Species::Pikachu, flawless_ivs: 3, probabilities: [0, 20, 40, 0, 0] },
  DenEncounter { species: types::Species::Pikachu, flawless_ivs: 3, probabilities: [0, 0, 20, 35, 0] },
  DenEncounter { species: types::Species::Manectric, flawless_ivs: 4, probabilities: [0, 0, 20, 25, 20] },
  DenEncounter { species: types::Species::Lanturn, flawless_ivs: 4, probabilities: [0, 0, 20, 25, 30] },
  DenEncounter { species: types::Species::Galvantula, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 30] },
  DenEncounter { species: types::Species::Vikavolt, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 10] },
  DenEncounter { species: types::Species::Raichu, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 10] },
];

#[rustfmt::skip]
const NEST_17491356DC666A54: DenEncounters = [
  DenEncounter { species: types::Species::Yamper, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Helioptile, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Toxel, flawless_ivs: 1, probabilities: [20, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Chinchou, flawless_ivs: 1, probabilities: [10, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Pikachu, flawless_ivs: 2, probabilities: [0, 20, 0, 0, 0] },
  DenEncounter { species: types::Species::Lanturn, flawless_ivs: 3, probabilities: [0, 20, 40, 0, 0] },
  DenEncounter { species: types::Species::Boltund, flawless_ivs: 3, probabilities: [0, 0, 20, 35, 0] },
  DenEncounter { species: types::Species::Heliolisk, flawless_ivs: 4, probabilities: [0, 0, 20, 25, 35] },
  DenEncounter { species: types::Species::Toxtricity, flawless_ivs: 4, probabilities: [0, 0, 20, 25, 30] },
  DenEncounter { species: types::Species::Pincurchin, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Togedemaru, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 10] },
  DenEncounter { species: types::Species::Morpeko, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 5] },
];

#[rustfmt::skip]
const NEST_17491656DC666F6D: DenEncounters = [
  DenEncounter { species: types::Species::Budew, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Seedot, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Bounsweet, flawless_ivs: 1, probabilities: [20, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Oddish, flawless_ivs: 1, probabilities: [10, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Nuzleaf, flawless_ivs: 2, probabilities: [0, 20, 0, 0, 0] },
  DenEncounter { species: types::Species::Roselia, flawless_ivs: 3, probabilities: [0, 20, 40, 0, 0] },
  DenEncounter { species: types::Species::Gloom, flawless_ivs: 3, probabilities: [0, 0, 20, 35, 0] },
  DenEncounter { species: types::Species::Steenee, flawless_ivs: 4, probabilities: [0, 0, 20, 25, 30] },
  DenEncounter { species: types::Species::Shiftry, flawless_ivs: 4, probabilities: [0, 0, 20, 25, 30] },
  DenEncounter { species: types::Species::Tsareena, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Vileplume, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Bellossom, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 5] },
];

#[rustfmt::skip]
const NEST_17491556DC666DBA: DenEncounters = [
  DenEncounter { species: types::Species::Budew, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Gossifleur, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Cottonee, flawless_ivs: 1, probabilities: [20, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Applin, flawless_ivs: 1, probabilities: [10, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Cherubi, flawless_ivs: 2, probabilities: [0, 20, 0, 0, 0] },
  DenEncounter { species: types::Species::Roselia, flawless_ivs: 2, probabilities: [0, 20, 40, 0, 0] },
  DenEncounter { species: types::Species::Ferroseed, flawless_ivs: 3, probabilities: [0, 0, 20, 35, 0] },
  DenEncounter { species: types::Species::Ferrothorn, flawless_ivs: 4, probabilities: [0, 0, 20, 25, 30] },
  DenEncounter { species: types::Species::Cherrim, flawless_ivs: 4, probabilities: [0, 0, 20, 25, 30] },
  DenEncounter { species: types::Species::Eldegoss, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 28] },
  DenEncounter { species: types::Species::Whimsicott, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 10] },
  DenEncounter { species: types::Species::Flapple, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 2] },
];

#[rustfmt::skip]
const NEST_17490856DC6657A3: DenEncounters = [
  DenEncounter { species: types::Species::Pumpkaboo, flawless_ivs: 1, probabilities: [10, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Phantump, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Pumpkaboo, flawless_ivs: 1, probabilities: [40, 35, 0, 0, 0] },
  DenEncounter { species: types::Species::Morelull, flawless_ivs: 1, probabilities: [15, 35, 0, 0, 0] },
  DenEncounter { species: types::Species::Pumpkaboo, flawless_ivs: 2, probabilities: [0, 5, 0, 0, 0] },
  DenEncounter { species: types::Species::Roselia, flawless_ivs: 2, probabilities: [0, 25, 40, 0, 0] },
  DenEncounter { species: types::Species::Shiinotic, flawless_ivs: 3, probabilities: [0, 0, 20, 35, 0] },
  DenEncounter { species: types::Species::Maractus, flawless_ivs: 4, probabilities: [0, 0, 20, 25, 30] },
  DenEncounter { species: types::Species::Trevenant, flawless_ivs: 4, probabilities: [0, 0, 20, 25, 30] },
  DenEncounter { species: types::Species::Gourgeist, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 29] },
  DenEncounter { species: types::Species::Dhelmise, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 10] },
  DenEncounter { species: types::Species::Pumpkaboo, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 1] },
];

#[rustfmt::skip]
const NEST_17490756DC6655F0: DenEncounters = [
  DenEncounter { species: types::Species::Stunky, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Trubbish, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Skorupi, flawless_ivs: 1, probabilities: [20, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Mareanie, flawless_ivs: 1, probabilities: [10, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Oddish, flawless_ivs: 2, probabilities: [0, 20, 0, 0, 0] },
  DenEncounter { species: types::Species::Roselia, flawless_ivs: 2, probabilities: [0, 20, 40, 0, 0] },
  DenEncounter { species: types::Species::Qwilfish, flawless_ivs: 3, probabilities: [0, 0, 20, 35, 0] },
  DenEncounter { species: types::Species::Drapion, flawless_ivs: 4, probabilities: [0, 0, 20, 25, 30] },
  DenEncounter { species: types::Species::Vileplume, flawless_ivs: 4, probabilities: [0, 0, 20, 25, 30] },
  DenEncounter { species: types::Species::Toxapex, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Garbodor, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Skuntank, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 5] },
];

#[rustfmt::skip]
const NEST_17458A56DC634BB2: DenEncounters = [
  DenEncounter { species: types::Species::Toxel, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Gastly, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Skorupi, flawless_ivs: 1, probabilities: [20, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Oddish, flawless_ivs: 1, probabilities: [10, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Gloom, flawless_ivs: 2, probabilities: [0, 20, 0, 0, 0] },
  DenEncounter { species: types::Species::Haunter, flawless_ivs: 2, probabilities: [0, 20, 40, 0, 0] },
  DenEncounter { species: types::Species::Koffing, flawless_ivs: 3, probabilities: [0, 0, 20, 35, 0] },
  DenEncounter { species: types::Species::Qwilfish, flawless_ivs: 4, probabilities: [0, 0, 20, 25, 30] },
  DenEncounter { species: types::Species::Vileplume, flawless_ivs: 4, probabilities: [0, 0, 20, 25, 30] },
  DenEncounter { species: types::Species::Roselia, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Toxtricity, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Weezing, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 5] },
];

#[rustfmt::skip]
const NEST_17458B56DC634D65: DenEncounters = [
  DenEncounter { species: types::Species::Pidove, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Hoothoot, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Natu, flawless_ivs: 1, probabilities: [20, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Rufflet, flawless_ivs: 1, probabilities: [10, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Woobat, flawless_ivs: 2, probabilities: [0, 20, 0, 0, 0] },
  DenEncounter { species: types::Species::Tranquill, flawless_ivs: 2, probabilities: [0, 20, 40, 0, 0] },
  DenEncounter { species: types::Species::Unfezant, flawless_ivs: 3, probabilities: [0, 0, 20, 35, 0] },
  DenEncounter { species: types::Species::Noctowl, flawless_ivs: 4, probabilities: [0, 0, 20, 25, 30] },
  DenEncounter { species: types::Species::Swoobat, flawless_ivs: 4, probabilities: [0, 0, 20, 25, 30] },
  DenEncounter { species: types::Species::Xatu, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Braviary, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Sigilyph, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 5] },
];

#[rustfmt::skip]
const NEST_17458856DC63484C: DenEncounters = [
  DenEncounter { species: types::Species::Rookidee, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Noibat, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Wingull, flawless_ivs: 1, probabilities: [20, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Natu, flawless_ivs: 1, probabilities: [10, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Drifloon, flawless_ivs: 2, probabilities: [0, 20, 0, 0, 0] },
  DenEncounter { species: types::Species::Corvisquire, flawless_ivs: 2, probabilities: [0, 20, 40, 0, 0] },
  DenEncounter { species: types::Species::Drifblim, flawless_ivs: 3, probabilities: [0, 0, 20, 35, 0] },
  DenEncounter { species: types::Species::Pelipper, flawless_ivs: 4, probabilities: [0, 0, 20, 25, 30] },
  DenEncounter { species: types::Species::Xatu, flawless_ivs: 4, probabilities: [0, 0, 20, 25, 30] },
  DenEncounter { species: types::Species::Corviknight, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Hawlucha, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Cramorant, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 5] },
];

#[rustfmt::skip]
const NEST_17458956DC6349FF: DenEncounters = [
  DenEncounter { species: types::Species::Cleffa, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Togepi, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Cutiefly, flawless_ivs: 1, probabilities: [20, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Swirlix, flawless_ivs: 1, probabilities: [10, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Clefairy, flawless_ivs: 2, probabilities: [0, 20, 0, 0, 0] },
  DenEncounter { species: types::Species::Morelull, flawless_ivs: 2, probabilities: [0, 20, 40, 0, 0] },
  DenEncounter { species: types::Species::Togetic, flawless_ivs: 3, probabilities: [0, 0, 20, 35, 0] },
  DenEncounter { species: types::Species::Clefable, flawless_ivs: 4, probabilities: [0, 0, 20, 25, 30] },
  DenEncounter { species: types::Species::Ribombee, flawless_ivs: 4, probabilities: [0, 0, 20, 25, 30] },
  DenEncounter { species: types::Species::Shiinotic, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Slurpuff, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Togekiss, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 5] },
];

#[rustfmt::skip]
const NEST_17458656DC6344E6: DenEncounters = [
  DenEncounter { species: types::Species::MimeJr, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Milcery, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Impidimp, flawless_ivs: 1, probabilities: [20, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Ralts, flawless_ivs: 1, probabilities: [10, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Clefairy, flawless_ivs: 2, probabilities: [0, 20, 0, 0, 0] },
  DenEncounter { species: types::Species::Kirlia, flawless_ivs: 2, probabilities: [0, 20, 40, 0, 0] },
  DenEncounter { species: types::Species::Morgrem, flawless_ivs: 3, probabilities: [0, 0, 20, 35, 0] },
  DenEncounter { species: types::Species::Clefable, flawless_ivs: 4, probabilities: [0, 0, 20, 25, 30] },
  DenEncounter { species: types::Species::Gardevoir, flawless_ivs: 4, probabilities: [0, 0, 20, 25, 30] },
  DenEncounter { species: types::Species::Alcremie, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Mawile, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Grimmsnarl, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 5] },
];

#[rustfmt::skip]
const NEST_17458756DC634699: DenEncounters = [
  DenEncounter { species: types::Species::Purrloin, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Stunky, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Sneasel, flawless_ivs: 1, probabilities: [20, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Inkay, flawless_ivs: 1, probabilities: [10, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Pawniard, flawless_ivs: 2, probabilities: [0, 20, 0, 0, 0] },
  DenEncounter { species: types::Species::Liepard, flawless_ivs: 2, probabilities: [0, 20, 40, 0, 0] },
  DenEncounter { species: types::Species::Skuntank, flawless_ivs: 3, probabilities: [0, 0, 20, 35, 0] },
  DenEncounter { species: types::Species::Weavile, flawless_ivs: 4, probabilities: [0, 0, 20, 25, 30] },
  DenEncounter { species: types::Species::Malamar, flawless_ivs: 4, probabilities: [0, 0, 20, 25, 30] },
  DenEncounter { species: types::Species::Bisharp, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Crawdaunt, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Shiftry, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 5] },
];

#[rustfmt::skip]
const NEST_17458456DC634180: DenEncounters = [
  DenEncounter { species: types::Species::Nickit, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Zigzagoon, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Purrloin, flawless_ivs: 1, probabilities: [20, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Impidimp, flawless_ivs: 1, probabilities: [10, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Deino, flawless_ivs: 2, probabilities: [0, 20, 0, 0, 0] },
  DenEncounter { species: types::Species::Thievul, flawless_ivs: 2, probabilities: [0, 20, 40, 0, 0] },
  DenEncounter { species: types::Species::Linoone, flawless_ivs: 3, probabilities: [0, 0, 20, 35, 0] },
  DenEncounter { species: types::Species::Morgrem, flawless_ivs: 4, probabilities: [0, 0, 20, 25, 30] },
  DenEncounter { species: types::Species::Grimmsnarl, flawless_ivs: 4, probabilities: [0, 0, 20, 25, 30] },
  DenEncounter { species: types::Species::Zweilous, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Obstagoon, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Hydreigon, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 5] },
];

#[rustfmt::skip]
const NEST_17458556DC634333: DenEncounters = [
  DenEncounter { species: types::Species::Noibat, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Trapinch, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Axew, flawless_ivs: 1, probabilities: [20, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Noibat, flawless_ivs: 1, probabilities: [10, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::JangmoO, flawless_ivs: 2, probabilities: [0, 20, 0, 0, 0] },
  DenEncounter { species: types::Species::Vibrava, flawless_ivs: 2, probabilities: [0, 20, 40, 0, 0] },
  DenEncounter { species: types::Species::HakamoO, flawless_ivs: 3, probabilities: [0, 0, 20, 35, 0] },
  DenEncounter { species: types::Species::Fraxure, flawless_ivs: 4, probabilities: [0, 0, 20, 25, 30] },
  DenEncounter { species: types::Species::Haxorus, flawless_ivs: 4, probabilities: [0, 0, 20, 25, 30] },
  DenEncounter { species: types::Species::Flygon, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Turtonator, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::KommoO, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 5] },
];

#[rustfmt::skip]
const NEST_17459256DC63594A: DenEncounters = [
  DenEncounter { species: types::Species::Noibat, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Applin, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::JangmoO, flawless_ivs: 1, probabilities: [20, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Dreepy, flawless_ivs: 1, probabilities: [10, 10, 0, 0, 0] },
  DenEncounter { species: types::Species::Noibat, flawless_ivs: 2, probabilities: [0, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Applin, flawless_ivs: 2, probabilities: [0, 30, 40, 0, 0] },
  DenEncounter { species: types::Species::Drakloak, flawless_ivs: 3, probabilities: [0, 0, 10, 10, 0] },
  DenEncounter { species: types::Species::Noivern, flawless_ivs: 4, probabilities: [0, 0, 25, 35, 35] },
  DenEncounter { species: types::Species::HakamoO, flawless_ivs: 4, probabilities: [0, 0, 25, 35, 35] },
  DenEncounter { species: types::Species::KommoO, flawless_ivs: 4, probabilities: [0, 0, 0, 20, 20] },
  DenEncounter { species: types::Species::Flapple, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 5] },
  DenEncounter { species: types::Species::Dragapult, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 5] },
];

#[rustfmt::skip]
const NEST_17459356DC635AFD: DenEncounters = [
  DenEncounter { species: types::Species::Bunnelby, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Hoothoot, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Pidove, flawless_ivs: 1, probabilities: [20, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Minccino, flawless_ivs: 1, probabilities: [10, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Helioptile, flawless_ivs: 2, probabilities: [0, 20, 0, 0, 0] },
  DenEncounter { species: types::Species::Stufful, flawless_ivs: 2, probabilities: [0, 20, 40, 0, 0] },
  DenEncounter { species: types::Species::Diggersby, flawless_ivs: 3, probabilities: [0, 0, 20, 35, 0] },
  DenEncounter { species: types::Species::Noctowl, flawless_ivs: 4, probabilities: [0, 0, 20, 25, 30] },
  DenEncounter { species: types::Species::Unfezant, flawless_ivs: 4, probabilities: [0, 0, 20, 25, 30] },
  DenEncounter { species: types::Species::Heliolisk, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Cinccino, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Bewear, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 5] },
];

#[rustfmt::skip]
const NEST_17501C56DC6C984D: DenEncounters = [
  DenEncounter { species: types::Species::Skwovet, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Wooloo, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Zigzagoon, flawless_ivs: 1, probabilities: [20, 40, 0, 0, 0] },
  DenEncounter { species: types::Species::Munchlax, flawless_ivs: 1, probabilities: [10, 10, 0, 0, 0] },
  DenEncounter { species: types::Species::Indeedee, flawless_ivs: 2, probabilities: [0, 10, 0, 0, 0] },
  DenEncounter { species: types::Species::Greedent, flawless_ivs: 2, probabilities: [0, 40, 40, 0, 0] },
  DenEncounter { species: types::Species::Linoone, flawless_ivs: 3, probabilities: [0, 0, 20, 35, 0] },
  DenEncounter { species: types::Species::Greedent, flawless_ivs: 4, probabilities: [0, 0, 20, 25, 30] },
  DenEncounter { species: types::Species::Dubwool, flawless_ivs: 4, probabilities: [0, 0, 20, 25, 30] },
  DenEncounter { species: types::Species::Diggersby, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Braviary, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Snorlax, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 5] },
];

#[rustfmt::skip]
const NEST_17501B56DC6C969A: DenEncounters = [
  DenEncounter { species: types::Species::Tympole, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Shellder, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Chinchou, flawless_ivs: 1, probabilities: [20, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Mareanie, flawless_ivs: 1, probabilities: [10, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Palpitoad, flawless_ivs: 2, probabilities: [0, 20, 0, 0, 0] },
  DenEncounter { species: types::Species::Arrokuda, flawless_ivs: 2, probabilities: [0, 20, 40, 0, 0] },
  DenEncounter { species: types::Species::Cloyster, flawless_ivs: 3, probabilities: [0, 0, 20, 10, 0] },
  DenEncounter { species: types::Species::Lanturn, flawless_ivs: 4, probabilities: [0, 0, 20, 20, 10] },
  DenEncounter { species: types::Species::Wishiwashi, flawless_ivs: 4, probabilities: [0, 0, 20, 20, 25] },
  DenEncounter { species: types::Species::Seismitoad, flawless_ivs: 4, probabilities: [0, 0, 0, 50, 25] },
  DenEncounter { species: types::Species::Barraskewda, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 20] },
  DenEncounter { species: types::Species::Toxapex, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 20] },
];

#[rustfmt::skip]
const NEST_17501A56DC6C94E7: DenEncounters = [
  DenEncounter { species: types::Species::Shellos, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Krabby, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Corphish, flawless_ivs: 1, probabilities: [20, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Chewtle, flawless_ivs: 1, probabilities: [10, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Binacle, flawless_ivs: 2, probabilities: [0, 20, 0, 0, 0] },
  DenEncounter { species: types::Species::Pyukumuku, flawless_ivs: 2, probabilities: [0, 20, 40, 0, 0] },
  DenEncounter { species: types::Species::Kingler, flawless_ivs: 3, probabilities: [0, 0, 20, 10, 0] },
  DenEncounter { species: types::Species::Crawdaunt, flawless_ivs: 4, probabilities: [0, 0, 20, 20, 10] },
  DenEncounter { species: types::Species::Barbaracle, flawless_ivs: 4, probabilities: [0, 0, 20, 20, 25] },
  DenEncounter { species: types::Species::Gastrodon, flawless_ivs: 4, probabilities: [0, 0, 0, 50, 25] },
  DenEncounter { species: types::Species::Jellicent, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 20] },
  DenEncounter { species: types::Species::Drednaw, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 20] },
];

#[rustfmt::skip]
const NEST_BA805C67100FD3F7: DenEncounters = [
  DenEncounter { species: types::Species::Gastly, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Yamask, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Sinistea, flawless_ivs: 1, probabilities: [20, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Duskull, flawless_ivs: 1, probabilities: [10, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Haunter, flawless_ivs: 2, probabilities: [0, 20, 30, 0, 0] },
  DenEncounter { species: types::Species::Pumpkaboo, flawless_ivs: 2, probabilities: [0, 20, 40, 20, 0] },
  DenEncounter { species: types::Species::Dusclops, flawless_ivs: 3, probabilities: [0, 0, 30, 20, 0] },
  DenEncounter { species: types::Species::Runerigus, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 1] },
  DenEncounter { species: types::Species::Polteageist, flawless_ivs: 4, probabilities: [0, 0, 0, 20, 45] },
  DenEncounter { species: types::Species::Gourgeist, flawless_ivs: 4, probabilities: [0, 0, 0, 40, 35] },
  DenEncounter { species: types::Species::Dusknoir, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Gengar, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 4] },
];

#[rustfmt::skip]
const NEST_BA805D67100FD5AA: DenEncounters = [
  DenEncounter { species: types::Species::Magikarp, flawless_ivs: 1, probabilities: [68, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Feebas, flawless_ivs: 1, probabilities: [2, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Arrokuda, flawless_ivs: 1, probabilities: [20, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Chewtle, flawless_ivs: 1, probabilities: [10, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Mareanie, flawless_ivs: 2, probabilities: [0, 20, 20, 0, 0] },
  DenEncounter { species: types::Species::Basculin, flawless_ivs: 2, probabilities: [0, 20, 40, 0, 0] },
  DenEncounter { species: types::Species::Qwilfish, flawless_ivs: 3, probabilities: [0, 0, 20, 20, 0] },
  DenEncounter { species: types::Species::Toxapex, flawless_ivs: 4, probabilities: [0, 0, 20, 20, 18] },
  DenEncounter { species: types::Species::Pyukumuku, flawless_ivs: 4, probabilities: [0, 0, 0, 20, 35] },
  DenEncounter { species: types::Species::Gyarados, flawless_ivs: 4, probabilities: [0, 0, 0, 40, 35] },
  DenEncounter { species: types::Species::Lapras, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 10] },
  DenEncounter { species: types::Species::Milotic, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 2] },
];

#[rustfmt::skip]
const NEST_BA805E67100FD75D: DenEncounters = [
  DenEncounter { species: types::Species::Riolu, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Bronzor, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Pawniard, flawless_ivs: 1, probabilities: [20, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Klink, flawless_ivs: 1, probabilities: [10, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Onix, flawless_ivs: 2, probabilities: [0, 20, 20, 0, 0] },
  DenEncounter { species: types::Species::Durant, flawless_ivs: 2, probabilities: [0, 20, 40, 0, 0] },
  DenEncounter { species: types::Species::Klang, flawless_ivs: 3, probabilities: [0, 0, 20, 20, 0] },
  DenEncounter { species: types::Species::Bronzong, flawless_ivs: 4, probabilities: [0, 0, 20, 20, 20] },
  DenEncounter { species: types::Species::Bisharp, flawless_ivs: 4, probabilities: [0, 0, 0, 20, 30] },
  DenEncounter { species: types::Species::Steelix, flawless_ivs: 4, probabilities: [0, 0, 0, 40, 30] },
  DenEncounter { species: types::Species::Klinklang, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Lucario, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 5] },
];

#[rustfmt::skip]
const NEST_BA805767100FCB78: DenEncounters = [
  DenEncounter { species: types::Species::Wimpod, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Blipbug, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Karrablast, flawless_ivs: 1, probabilities: [20, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Dewpider, flawless_ivs: 1, probabilities: [10, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Shelmet, flawless_ivs: 2, probabilities: [0, 20, 20, 0, 0] },
  DenEncounter { species: types::Species::Dwebble, flawless_ivs: 2, probabilities: [0, 20, 40, 0, 0] },
  DenEncounter { species: types::Species::Dottler, flawless_ivs: 3, probabilities: [0, 0, 20, 20, 0] },
  DenEncounter { species: types::Species::Orbeetle, flawless_ivs: 4, probabilities: [0, 0, 20, 20, 20] },
  DenEncounter { species: types::Species::Araquanid, flawless_ivs: 4, probabilities: [0, 0, 0, 20, 30] },
  DenEncounter { species: types::Species::Golisopod, flawless_ivs: 4, probabilities: [0, 0, 0, 40, 30] },
  DenEncounter { species: types::Species::Escavalier, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Shedinja, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 5] },
];

#[rustfmt::skip]
const NEST_BA805867100FCD2B: DenEncounters = [
  DenEncounter { species: types::Species::Honedge, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Yamask, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Sinistea, flawless_ivs: 1, probabilities: [20, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Drifloon, flawless_ivs: 1, probabilities: [10, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Doublade, flawless_ivs: 2, probabilities: [0, 20, 20, 0, 0] },
  DenEncounter { species: types::Species::Pumpkaboo, flawless_ivs: 3, probabilities: [0, 20, 40, 10, 0] },
  DenEncounter { species: types::Species::Drifblim, flawless_ivs: 3, probabilities: [0, 0, 20, 10, 0] },
  DenEncounter { species: types::Species::Gourgeist, flawless_ivs: 4, probabilities: [0, 0, 20, 20, 35] },
  DenEncounter { species: types::Species::Polteageist, flawless_ivs: 4, probabilities: [0, 0, 0, 20, 30] },
  DenEncounter { species: types::Species::Gourgeist, flawless_ivs: 4, probabilities: [0, 0, 0, 40, 29] },
  DenEncounter { species: types::Species::Runerigus, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 1] },
  DenEncounter { species: types::Species::Aegislash, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 5] },
];

#[rustfmt::skip]
const NEST_BA805967100FCEDE: DenEncounters = [
  DenEncounter { species: types::Species::Riolu, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Machop, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Scraggy, flawless_ivs: 1, probabilities: [20, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Stufful, flawless_ivs: 1, probabilities: [10, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Bewear, flawless_ivs: 2, probabilities: [0, 20, 20, 0, 0] },
  DenEncounter { species: types::Species::Falinks, flawless_ivs: 3, probabilities: [0, 20, 40, 10, 0] },
  DenEncounter { species: types::Species::Machoke, flawless_ivs: 3, probabilities: [0, 0, 20, 10, 0] },
  DenEncounter { species: types::Species::Scrafty, flawless_ivs: 4, probabilities: [0, 0, 20, 20, 35] },
  DenEncounter { species: types::Species::Machamp, flawless_ivs: 4, probabilities: [0, 0, 0, 20, 30] },
  DenEncounter { species: types::Species::Passimian, flawless_ivs: 4, probabilities: [0, 0, 0, 40, 25] },
  DenEncounter { species: types::Species::Lucario, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 5] },
  DenEncounter { species: types::Species::Gallade, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 5] },
];

#[rustfmt::skip]
const NEST_BA805A67100FD091: DenEncounters = [
  DenEncounter { species: types::Species::Meowth, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Bronzor, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Pawniard, flawless_ivs: 1, probabilities: [20, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Ferroseed, flawless_ivs: 1, probabilities: [10, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Honedge, flawless_ivs: 2, probabilities: [0, 20, 30, 0, 0] },
  DenEncounter { species: types::Species::Bronzong, flawless_ivs: 2, probabilities: [0, 20, 40, 0, 0] },
  DenEncounter { species: types::Species::Perrserker, flawless_ivs: 4, probabilities: [0, 0, 0, 20, 20] },
  DenEncounter { species: types::Species::Ferrothorn, flawless_ivs: 4, probabilities: [0, 0, 30, 20, 10] },
  DenEncounter { species: types::Species::Bisharp, flawless_ivs: 4, probabilities: [0, 0, 0, 20, 25] },
  DenEncounter { species: types::Species::Stunfisk, flawless_ivs: 4, probabilities: [0, 0, 0, 40, 25] },
  DenEncounter { species: types::Species::Copperajah, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Duraludon, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 5] },
];

#[rustfmt::skip]
const NEST_BA805367100FC4AC: DenEncounters = [
  DenEncounter { species: types::Species::Inkay, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Ralts, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::MrMime, flawless_ivs: 1, probabilities: [20, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Woobat, flawless_ivs: 1, probabilities: [10, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Hatenna, flawless_ivs: 2, probabilities: [0, 20, 20, 0, 0] },
  DenEncounter { species: types::Species::Hattrem, flawless_ivs: 2, probabilities: [0, 20, 40, 0, 0] },
  DenEncounter { species: types::Species::Kirlia, flawless_ivs: 3, probabilities: [0, 0, 20, 20, 0] },
  DenEncounter { species: types::Species::Swoobat, flawless_ivs: 4, probabilities: [0, 0, 20, 20, 20] },
  DenEncounter { species: types::Species::Hatterene, flawless_ivs: 4, probabilities: [0, 0, 0, 20, 30] },
  DenEncounter { species: types::Species::MrRime, flawless_ivs: 4, probabilities: [0, 0, 0, 40, 30] },
  DenEncounter { species: types::Species::Malamar, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Gardevoir, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 5] },
];

#[rustfmt::skip]
const NEST_BA805467100FC65F: DenEncounters = [
  DenEncounter { species: types::Species::Dwebble, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Bonsly, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Rolycoly, flawless_ivs: 1, probabilities: [20, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Binacle, flawless_ivs: 1, probabilities: [10, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Carkol, flawless_ivs: 2, probabilities: [0, 20, 20, 0, 0] },
  DenEncounter { species: types::Species::Sudowoodo, flawless_ivs: 2, probabilities: [0, 20, 40, 0, 0] },
  DenEncounter { species: types::Species::Barbaracle, flawless_ivs: 3, probabilities: [0, 0, 20, 20, 0] },
  DenEncounter { species: types::Species::Onix, flawless_ivs: 4, probabilities: [0, 0, 20, 20, 20] },
  DenEncounter { species: types::Species::Crustle, flawless_ivs: 4, probabilities: [0, 0, 0, 20, 30] },
  DenEncounter { species: types::Species::Coalossal, flawless_ivs: 4, probabilities: [0, 0, 0, 40, 30] },
  DenEncounter { species: types::Species::Steelix, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Stonjourner, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 5] },
];

#[rustfmt::skip]
const NEST_BA83E1671012EBCD: DenEncounters = [
  DenEncounter { species: types::Species::Wooper, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Barboach, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Yamask, flawless_ivs: 1, probabilities: [20, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Golett, flawless_ivs: 1, probabilities: [10, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Palpitoad, flawless_ivs: 2, probabilities: [0, 20, 20, 0, 0] },
  DenEncounter { species: types::Species::Quagsire, flawless_ivs: 2, probabilities: [0, 20, 40, 0, 0] },
  DenEncounter { species: types::Species::Stunfisk, flawless_ivs: 3, probabilities: [0, 0, 20, 20, 0] },
  DenEncounter { species: types::Species::Golurk, flawless_ivs: 4, probabilities: [0, 0, 20, 20, 30] },
  DenEncounter { species: types::Species::Gastrodon, flawless_ivs: 4, probabilities: [0, 0, 0, 20, 35] },
  DenEncounter { species: types::Species::Seismitoad, flawless_ivs: 4, probabilities: [0, 0, 0, 40, 30] },
  DenEncounter { species: types::Species::Runerigus, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 1] },
  DenEncounter { species: types::Species::Rhyperior, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 4] },
];

#[rustfmt::skip]
const NEST_BA83E0671012EA1A: DenEncounters = [
  DenEncounter { species: types::Species::Vulpix, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Sizzlipede, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Litwick, flawless_ivs: 1, probabilities: [20, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Charmander, flawless_ivs: 1, probabilities: [10, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Charmeleon, flawless_ivs: 2, probabilities: [0, 20, 20, 0, 0] },
  DenEncounter { species: types::Species::Ninetales, flawless_ivs: 2, probabilities: [0, 20, 40, 0, 0] },
  DenEncounter { species: types::Species::Heatmor, flawless_ivs: 3, probabilities: [0, 0, 20, 20, 0] },
  DenEncounter { species: types::Species::Torkoal, flawless_ivs: 4, probabilities: [0, 0, 20, 20, 20] },
  DenEncounter { species: types::Species::Ninetales, flawless_ivs: 4, probabilities: [0, 0, 0, 20, 30] },
  DenEncounter { species: types::Species::Salazzle, flawless_ivs: 4, probabilities: [0, 0, 0, 40, 30] },
  DenEncounter { species: types::Species::Centiskorch, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Charizard, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 5] },
];

#[rustfmt::skip]
const NEST_BA83DF671012E867: DenEncounters = [
  DenEncounter { species: types::Species::Vulpix, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Sizzlipede, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Litwick, flawless_ivs: 1, probabilities: [20, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Salandit, flawless_ivs: 1, probabilities: [10, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Carkol, flawless_ivs: 2, probabilities: [0, 20, 20, 0, 0] },
  DenEncounter { species: types::Species::Lampent, flawless_ivs: 2, probabilities: [0, 20, 40, 0, 0] },
  DenEncounter { species: types::Species::Heatmor, flawless_ivs: 3, probabilities: [0, 0, 20, 20, 0] },
  DenEncounter { species: types::Species::Torkoal, flawless_ivs: 4, probabilities: [0, 0, 20, 20, 20] },
  DenEncounter { species: types::Species::Ninetales, flawless_ivs: 4, probabilities: [0, 0, 0, 20, 30] },
  DenEncounter { species: types::Species::Chandelure, flawless_ivs: 4, probabilities: [0, 0, 0, 40, 30] },
  DenEncounter { species: types::Species::Coalossal, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Turtonator, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 5] },
];

#[rustfmt::skip]
const NEST_BA83DE671012E6B4: DenEncounters = [
  DenEncounter { species: types::Species::Vanillite, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Darumaka, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::MrMime, flawless_ivs: 1, probabilities: [20, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Bergmite, flawless_ivs: 1, probabilities: [10, 40, 0, 0, 0] },
  DenEncounter { species: types::Species::Snorunt, flawless_ivs: 2, probabilities: [0, 25, 30, 0, 0] },
  DenEncounter { species: types::Species::Delibird, flawless_ivs: 2, probabilities: [0, 5, 5, 0, 0] },
  DenEncounter { species: types::Species::Avalugg, flawless_ivs: 3, probabilities: [0, 0, 35, 20, 0] },
  DenEncounter { species: types::Species::Glalie, flawless_ivs: 4, probabilities: [0, 0, 30, 20, 10] },
  DenEncounter { species: types::Species::Vanilluxe, flawless_ivs: 4, probabilities: [0, 0, 0, 20, 25] },
  DenEncounter { species: types::Species::MrRime, flawless_ivs: 4, probabilities: [0, 0, 0, 40, 25] },
  DenEncounter { species: types::Species::Lapras, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 35] },
  DenEncounter { species: types::Species::Darmanitan, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 5] },
];

#[rustfmt::skip]
const NEST_BA83DD671012E501: DenEncounters = [
  DenEncounter { species: types::Species::Yamper, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Toxel, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Pikachu, flawless_ivs: 1, probabilities: [20, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Joltik, flawless_ivs: 1, probabilities: [10, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Chinchou, flawless_ivs: 2, probabilities: [0, 20, 20, 0, 0] },
  DenEncounter { species: types::Species::Lanturn, flawless_ivs: 2, probabilities: [0, 20, 40, 0, 0] },
  DenEncounter { species: types::Species::Boltund, flawless_ivs: 4, probabilities: [0, 0, 20, 20, 10] },
  DenEncounter { species: types::Species::Toxtricity, flawless_ivs: 4, probabilities: [0, 0, 20, 20, 20] },
  DenEncounter { species: types::Species::Pincurchin, flawless_ivs: 4, probabilities: [0, 0, 0, 20, 25] },
  DenEncounter { species: types::Species::Galvantula, flawless_ivs: 4, probabilities: [0, 0, 0, 40, 25] },
  DenEncounter { species: types::Species::Togedemaru, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Morpeko, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 5] },
];

#[rustfmt::skip]
const NEST_BA83DC671012E34E: DenEncounters = [
  DenEncounter { species: types::Species::Pichu, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Electrike, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Toxel, flawless_ivs: 1, probabilities: [20, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Helioptile, flawless_ivs: 1, probabilities: [10, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Joltik, flawless_ivs: 2, probabilities: [0, 20, 20, 0, 0] },
  DenEncounter { species: types::Species::Pikachu, flawless_ivs: 2, probabilities: [0, 20, 40, 0, 0] },
  DenEncounter { species: types::Species::Pikachu, flawless_ivs: 4, probabilities: [0, 0, 20, 20, 10] },
  DenEncounter { species: types::Species::Rotom, flawless_ivs: 4, probabilities: [0, 0, 20, 20, 20] },
  DenEncounter { species: types::Species::Rotom, flawless_ivs: 4, probabilities: [0, 0, 0, 20, 25] },
  DenEncounter { species: types::Species::Rotom, flawless_ivs: 4, probabilities: [0, 0, 0, 40, 25] },
  DenEncounter { species: types::Species::Rotom, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Rotom, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 5] },
];

#[rustfmt::skip]
const NEST_BA83DB671012E19B: DenEncounters = [
  DenEncounter { species: types::Species::Budew, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Seedot, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Gossifleur, flawless_ivs: 1, probabilities: [20, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Ferroseed, flawless_ivs: 1, probabilities: [10, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Nuzleaf, flawless_ivs: 2, probabilities: [0, 20, 20, 0, 0] },
  DenEncounter { species: types::Species::Applin, flawless_ivs: 2, probabilities: [0, 20, 40, 0, 0] },
  DenEncounter { species: types::Species::Roselia, flawless_ivs: 4, probabilities: [0, 0, 20, 20, 10] },
  DenEncounter { species: types::Species::Shiftry, flawless_ivs: 4, probabilities: [0, 0, 20, 20, 20] },
  DenEncounter { species: types::Species::Eldegoss, flawless_ivs: 4, probabilities: [0, 0, 0, 20, 25] },
  DenEncounter { species: types::Species::Ferrothorn, flawless_ivs: 4, probabilities: [0, 0, 0, 40, 25] },
  DenEncounter { species: types::Species::Roserade, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Flapple, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 5] },
];

#[rustfmt::skip]
const NEST_BA83DA671012DFE8: DenEncounters = [
  DenEncounter { species: types::Species::Cherubi, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Seedot, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Gossifleur, flawless_ivs: 1, probabilities: [20, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Cottonee, flawless_ivs: 1, probabilities: [10, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Nuzleaf, flawless_ivs: 2, probabilities: [0, 20, 20, 0, 0] },
  DenEncounter { species: types::Species::Morelull, flawless_ivs: 2, probabilities: [0, 20, 40, 0, 0] },
  DenEncounter { species: types::Species::Cherrim, flawless_ivs: 4, probabilities: [0, 0, 20, 20, 10] },
  DenEncounter { species: types::Species::Shiinotic, flawless_ivs: 4, probabilities: [0, 0, 20, 20, 20] },
  DenEncounter { species: types::Species::Eldegoss, flawless_ivs: 4, probabilities: [0, 0, 0, 20, 25] },
  DenEncounter { species: types::Species::Whimsicott, flawless_ivs: 4, probabilities: [0, 0, 0, 40, 25] },
  DenEncounter { species: types::Species::Shiftry, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Dhelmise, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 5] },
];

#[rustfmt::skip]
const NEST_BA83D9671012DE35: DenEncounters = [
  DenEncounter { species: types::Species::Stunky, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Trubbish, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Skorupi, flawless_ivs: 1, probabilities: [20, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Koffing, flawless_ivs: 1, probabilities: [10, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Mareanie, flawless_ivs: 2, probabilities: [0, 20, 20, 0, 0] },
  DenEncounter { species: types::Species::Toxel, flawless_ivs: 2, probabilities: [0, 20, 40, 0, 0] },
  DenEncounter { species: types::Species::Garbodor, flawless_ivs: 4, probabilities: [0, 0, 20, 20, 10] },
  DenEncounter { species: types::Species::Drapion, flawless_ivs: 4, probabilities: [0, 0, 20, 20, 20] },
  DenEncounter { species: types::Species::Toxtricity, flawless_ivs: 4, probabilities: [0, 0, 0, 20, 25] },
  DenEncounter { species: types::Species::Skuntank, flawless_ivs: 4, probabilities: [0, 0, 0, 40, 25] },
  DenEncounter { species: types::Species::Weezing, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Toxapex, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 5] },
];

#[rustfmt::skip]
const NEST_BA83D8671012DC82: DenEncounters = [
  DenEncounter { species: types::Species::Natu, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Hoothoot, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Rookidee, flawless_ivs: 1, probabilities: [20, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Wingull, flawless_ivs: 1, probabilities: [10, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Butterfree, flawless_ivs: 2, probabilities: [0, 20, 20, 0, 0] },
  DenEncounter { species: types::Species::Corvisquire, flawless_ivs: 2, probabilities: [0, 20, 40, 0, 0] },
  DenEncounter { species: types::Species::Noctowl, flawless_ivs: 4, probabilities: [0, 0, 20, 20, 10] },
  DenEncounter { species: types::Species::Pelipper, flawless_ivs: 4, probabilities: [0, 0, 20, 20, 20] },
  DenEncounter { species: types::Species::Xatu, flawless_ivs: 4, probabilities: [0, 0, 0, 20, 25] },
  DenEncounter { species: types::Species::Hawlucha, flawless_ivs: 4, probabilities: [0, 0, 0, 40, 25] },
  DenEncounter { species: types::Species::Corviknight, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Delibird, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 5] },
];

#[rustfmt::skip]
const NEST_BA8747671015CEF6: DenEncounters = [
  DenEncounter { species: types::Species::Togepi, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Morelull, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Impidimp, flawless_ivs: 1, probabilities: [20, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Ralts, flawless_ivs: 1, probabilities: [10, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Togetic, flawless_ivs: 2, probabilities: [0, 20, 20, 0, 0] },
  DenEncounter { species: types::Species::Shiinotic, flawless_ivs: 2, probabilities: [0, 20, 40, 0, 0] },
  DenEncounter { species: types::Species::Morgrem, flawless_ivs: 4, probabilities: [0, 0, 20, 20, 10] },
  DenEncounter { species: types::Species::Mawile, flawless_ivs: 4, probabilities: [0, 0, 20, 20, 20] },
  DenEncounter { species: types::Species::Gardevoir, flawless_ivs: 4, probabilities: [0, 0, 0, 20, 25] },
  DenEncounter { species: types::Species::Togekiss, flawless_ivs: 4, probabilities: [0, 0, 0, 40, 25] },
  DenEncounter { species: types::Species::Grimmsnarl, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Mimikyu, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 5] },
];

#[rustfmt::skip]
const NEST_BA8748671015D0A9: DenEncounters = [
  DenEncounter { species: types::Species::Nickit, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Zigzagoon, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Scraggy, flawless_ivs: 1, probabilities: [20, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Sneasel, flawless_ivs: 1, probabilities: [10, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Liepard, flawless_ivs: 2, probabilities: [0, 20, 20, 0, 0] },
  DenEncounter { species: types::Species::Linoone, flawless_ivs: 2, probabilities: [0, 20, 40, 0, 0] },
  DenEncounter { species: types::Species::Thievul, flawless_ivs: 4, probabilities: [0, 0, 20, 20, 10] },
  DenEncounter { species: types::Species::Pangoro, flawless_ivs: 4, probabilities: [0, 0, 20, 20, 20] },
  DenEncounter { species: types::Species::Weavile, flawless_ivs: 4, probabilities: [0, 0, 0, 20, 25] },
  DenEncounter { species: types::Species::Scrafty, flawless_ivs: 4, probabilities: [0, 0, 0, 40, 25] },
  DenEncounter { species: types::Species::Obstagoon, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Hydreigon, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 5] },
];

#[rustfmt::skip]
const NEST_BA8745671015CB90: DenEncounters = [
  DenEncounter { species: types::Species::Trapinch, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Applin, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Axew, flawless_ivs: 1, probabilities: [20, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::JangmoO, flawless_ivs: 1, probabilities: [10, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Dreepy, flawless_ivs: 2, probabilities: [0, 20, 20, 0, 0] },
  DenEncounter { species: types::Species::Fraxure, flawless_ivs: 2, probabilities: [0, 20, 40, 0, 0] },
  DenEncounter { species: types::Species::HakamoO, flawless_ivs: 4, probabilities: [0, 0, 20, 20, 10] },
  DenEncounter { species: types::Species::Turtonator, flawless_ivs: 4, probabilities: [0, 0, 20, 20, 20] },
  DenEncounter { species: types::Species::KommoO, flawless_ivs: 4, probabilities: [0, 0, 0, 20, 25] },
  DenEncounter { species: types::Species::Drakloak, flawless_ivs: 4, probabilities: [0, 0, 0, 40, 25] },
  DenEncounter { species: types::Species::Haxorus, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Dragapult, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 5] },
];

#[rustfmt::skip]
const NEST_BA8746671015CD43: DenEncounters = [
  DenEncounter { species: types::Species::Bunnelby, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Pidove, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Skwovet, flawless_ivs: 1, probabilities: [20, 40, 0, 0, 0] },
  DenEncounter { species: types::Species::Eevee, flawless_ivs: 1, probabilities: [10, 10, 0, 0, 0] },
  DenEncounter { species: types::Species::Tranquill, flawless_ivs: 2, probabilities: [0, 25, 20, 0, 0] },
  DenEncounter { species: types::Species::Wooloo, flawless_ivs: 2, probabilities: [0, 25, 40, 0, 0] },
  DenEncounter { species: types::Species::Unfezant, flawless_ivs: 4, probabilities: [0, 0, 20, 20, 10] },
  DenEncounter { species: types::Species::Dubwool, flawless_ivs: 4, probabilities: [0, 0, 20, 20, 20] },
  DenEncounter { species: types::Species::Braviary, flawless_ivs: 4, probabilities: [0, 0, 0, 20, 25] },
  DenEncounter { species: types::Species::Indeedee, flawless_ivs: 4, probabilities: [0, 0, 0, 40, 25] },
  DenEncounter { species: types::Species::Eevee, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Snorlax, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 5] },
];

#[rustfmt::skip]
const NEST_BA874B671015D5C2: DenEncounters = [
  DenEncounter { species: types::Species::Ditto, flawless_ivs: 1, probabilities: [25, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Ditto, flawless_ivs: 1, probabilities: [25, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Ditto, flawless_ivs: 2, probabilities: [25, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Ditto, flawless_ivs: 2, probabilities: [25, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Ditto, flawless_ivs: 3, probabilities: [0, 25, 25, 0, 0] },
  DenEncounter { species: types::Species::Ditto, flawless_ivs: 3, probabilities: [0, 25, 25, 0, 0] },
  DenEncounter { species: types::Species::Ditto, flawless_ivs: 3, probabilities: [0, 0, 25, 25, 0] },
  DenEncounter { species: types::Species::Ditto, flawless_ivs: 3, probabilities: [0, 0, 25, 25, 0] },
  DenEncounter { species: types::Species::Ditto, flawless_ivs: 4, probabilities: [0, 0, 0, 25, 25] },
  DenEncounter { species: types::Species::Ditto, flawless_ivs: 4, probabilities: [0, 0, 0, 25, 25] },
  DenEncounter { species: types::Species::Ditto, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 25] },
  DenEncounter { species: types::Species::Ditto, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 25] },
];

#[rustfmt::skip]
const NEST_BA874C671015D775: DenEncounters = [
  DenEncounter { species: types::Species::Mantyke, flawless_ivs: 1, probabilities: [68, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Corphish, flawless_ivs: 1, probabilities: [2, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Arrokuda, flawless_ivs: 1, probabilities: [20, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Chewtle, flawless_ivs: 1, probabilities: [10, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Mareanie, flawless_ivs: 2, probabilities: [0, 20, 20, 0, 0] },
  DenEncounter { species: types::Species::Basculin, flawless_ivs: 2, probabilities: [0, 20, 40, 0, 0] },
  DenEncounter { species: types::Species::Crawdaunt, flawless_ivs: 3, probabilities: [0, 0, 20, 20, 0] },
  DenEncounter { species: types::Species::Toxapex, flawless_ivs: 4, probabilities: [0, 0, 20, 20, 15] },
  DenEncounter { species: types::Species::Pyukumuku, flawless_ivs: 4, probabilities: [0, 0, 0, 20, 35] },
  DenEncounter { species: types::Species::Mantine, flawless_ivs: 4, probabilities: [0, 0, 0, 40, 35] },
  DenEncounter { species: types::Species::Lapras, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 10] },
  DenEncounter { species: types::Species::Vaporeon, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 5] },
];

#[rustfmt::skip]
const NEST_BA8749671015D25C: DenEncounters = [
  DenEncounter { species: types::Species::Inkay, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Bronzor, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::MrMime, flawless_ivs: 1, probabilities: [20, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Woobat, flawless_ivs: 1, probabilities: [10, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Hatenna, flawless_ivs: 2, probabilities: [0, 20, 20, 0, 0] },
  DenEncounter { species: types::Species::Hattrem, flawless_ivs: 2, probabilities: [0, 20, 40, 0, 0] },
  DenEncounter { species: types::Species::Bronzong, flawless_ivs: 3, probabilities: [0, 0, 20, 20, 0] },
  DenEncounter { species: types::Species::Swoobat, flawless_ivs: 4, probabilities: [0, 0, 20, 20, 20] },
  DenEncounter { species: types::Species::Malamar, flawless_ivs: 4, probabilities: [0, 0, 0, 20, 30] },
  DenEncounter { species: types::Species::MrRime, flawless_ivs: 4, probabilities: [0, 0, 0, 40, 30] },
  DenEncounter { species: types::Species::Hatterene, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Espeon, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 5] },
];

#[rustfmt::skip]
const NEST_BA874A671015D40F: DenEncounters = [
  DenEncounter { species: types::Species::Nickit, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Zigzagoon, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Inkay, flawless_ivs: 1, probabilities: [20, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Pawniard, flawless_ivs: 1, probabilities: [10, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Liepard, flawless_ivs: 2, probabilities: [0, 20, 20, 0, 0] },
  DenEncounter { species: types::Species::Linoone, flawless_ivs: 2, probabilities: [0, 20, 40, 0, 0] },
  DenEncounter { species: types::Species::Thievul, flawless_ivs: 4, probabilities: [0, 0, 20, 20, 10] },
  DenEncounter { species: types::Species::Pangoro, flawless_ivs: 4, probabilities: [0, 0, 20, 20, 20] },
  DenEncounter { species: types::Species::Bisharp, flawless_ivs: 4, probabilities: [0, 0, 0, 20, 25] },
  DenEncounter { species: types::Species::Malamar, flawless_ivs: 4, probabilities: [0, 0, 0, 40, 25] },
  DenEncounter { species: types::Species::Obstagoon, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Umbreon, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 5] },
];

#[rustfmt::skip]
const NEST_BA874F671015DC8E: DenEncounters = [
  DenEncounter { species: types::Species::Cherubi, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Bounsweet, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Gossifleur, flawless_ivs: 1, probabilities: [20, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Cottonee, flawless_ivs: 1, probabilities: [10, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Steenee, flawless_ivs: 2, probabilities: [0, 20, 20, 0, 0] },
  DenEncounter { species: types::Species::Ferroseed, flawless_ivs: 2, probabilities: [0, 20, 40, 0, 0] },
  DenEncounter { species: types::Species::Cherrim, flawless_ivs: 4, probabilities: [0, 0, 20, 20, 10] },
  DenEncounter { species: types::Species::Ferrothorn, flawless_ivs: 4, probabilities: [0, 0, 20, 20, 20] },
  DenEncounter { species: types::Species::Eldegoss, flawless_ivs: 4, probabilities: [0, 0, 0, 20, 25] },
  DenEncounter { species: types::Species::Tsareena, flawless_ivs: 4, probabilities: [0, 0, 0, 40, 25] },
  DenEncounter { species: types::Species::Whimsicott, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Leafeon, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 5] },
];

#[rustfmt::skip]
const NEST_BA8750671015DE41: DenEncounters = [
  DenEncounter { species: types::Species::Vulpix, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Sizzlipede, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Litwick, flawless_ivs: 1, probabilities: [20, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Vulpix, flawless_ivs: 1, probabilities: [10, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Carkol, flawless_ivs: 2, probabilities: [0, 20, 20, 0, 0] },
  DenEncounter { species: types::Species::Lampent, flawless_ivs: 2, probabilities: [0, 20, 40, 0, 0] },
  DenEncounter { species: types::Species::Heatmor, flawless_ivs: 3, probabilities: [0, 0, 20, 20, 0] },
  DenEncounter { species: types::Species::Torkoal, flawless_ivs: 4, probabilities: [0, 0, 20, 20, 20] },
  DenEncounter { species: types::Species::Arcanine, flawless_ivs: 4, probabilities: [0, 0, 0, 10, 30] },
  DenEncounter { species: types::Species::Ninetales, flawless_ivs: 4, probabilities: [0, 0, 0, 50, 30] },
  DenEncounter { species: types::Species::Chandelure, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Flareon, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 5] },
];

#[rustfmt::skip]
const NEST_BA8A4D6710180EFF: DenEncounters = [
  DenEncounter { species: types::Species::Yamper, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Toxel, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Pikachu, flawless_ivs: 1, probabilities: [20, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Helioptile, flawless_ivs: 1, probabilities: [10, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Chinchou, flawless_ivs: 2, probabilities: [0, 20, 20, 0, 0] },
  DenEncounter { species: types::Species::Lanturn, flawless_ivs: 2, probabilities: [0, 20, 40, 0, 0] },
  DenEncounter { species: types::Species::Boltund, flawless_ivs: 4, probabilities: [0, 0, 20, 20, 10] },
  DenEncounter { species: types::Species::Toxtricity, flawless_ivs: 4, probabilities: [0, 0, 20, 20, 20] },
  DenEncounter { species: types::Species::Heliolisk, flawless_ivs: 4, probabilities: [0, 0, 0, 20, 25] },
  DenEncounter { species: types::Species::Vikavolt, flawless_ivs: 4, probabilities: [0, 0, 0, 40, 25] },
  DenEncounter { species: types::Species::Pikachu, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Jolteon, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 5] },
];

#[rustfmt::skip]
const NEST_BA8A4C6710180D4C: DenEncounters = [
  DenEncounter { species: types::Species::Vanillite, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Snom, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::MrMime, flawless_ivs: 1, probabilities: [20, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Bergmite, flawless_ivs: 1, probabilities: [10, 40, 0, 0, 0] },
  DenEncounter { species: types::Species::Snorunt, flawless_ivs: 2, probabilities: [0, 25, 30, 0, 0] },
  DenEncounter { species: types::Species::Vanillish, flawless_ivs: 2, probabilities: [0, 5, 5, 0, 0] },
  DenEncounter { species: types::Species::Avalugg, flawless_ivs: 3, probabilities: [0, 0, 35, 20, 0] },
  DenEncounter { species: types::Species::Frosmoth, flawless_ivs: 4, probabilities: [0, 0, 30, 20, 35] },
  DenEncounter { species: types::Species::Vanilluxe, flawless_ivs: 4, probabilities: [0, 0, 0, 20, 25] },
  DenEncounter { species: types::Species::MrRime, flawless_ivs: 4, probabilities: [0, 0, 0, 40, 25] },
  DenEncounter { species: types::Species::Froslass, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 10] },
  DenEncounter { species: types::Species::Glaceon, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 5] },
];

#[rustfmt::skip]
const NEST_BA8A4F6710181265: DenEncounters = [
  DenEncounter { species: types::Species::Togepi, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Swirlix, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Impidimp, flawless_ivs: 1, probabilities: [20, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Ralts, flawless_ivs: 1, probabilities: [10, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Togetic, flawless_ivs: 2, probabilities: [0, 20, 20, 0, 0] },
  DenEncounter { species: types::Species::Morgrem, flawless_ivs: 2, probabilities: [0, 20, 40, 0, 0] },
  DenEncounter { species: types::Species::Slurpuff, flawless_ivs: 4, probabilities: [0, 0, 20, 20, 10] },
  DenEncounter { species: types::Species::Milcery, flawless_ivs: 4, probabilities: [0, 0, 20, 20, 20] },
  DenEncounter { species: types::Species::Gardevoir, flawless_ivs: 4, probabilities: [0, 0, 0, 20, 25] },
  DenEncounter { species: types::Species::Grimmsnarl, flawless_ivs: 4, probabilities: [0, 0, 0, 40, 25] },
  DenEncounter { species: types::Species::Togekiss, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Sylveon, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 5] },
];

#[rustfmt::skip]
const NEST_BA8A4E67101810B2: DenEncounters = [
  DenEncounter { species: types::Species::Magikarp, flawless_ivs: 1, probabilities: [68, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Dewpider, flawless_ivs: 1, probabilities: [2, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Wooper, flawless_ivs: 1, probabilities: [20, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Barboach, flawless_ivs: 1, probabilities: [10, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Krabby, flawless_ivs: 2, probabilities: [0, 20, 20, 0, 0] },
  DenEncounter { species: types::Species::Wishiwashi, flawless_ivs: 2, probabilities: [0, 20, 40, 0, 0] },
  DenEncounter { species: types::Species::Kingler, flawless_ivs: 3, probabilities: [0, 0, 20, 20, 0] },
  DenEncounter { species: types::Species::Whiscash, flawless_ivs: 4, probabilities: [0, 0, 20, 20, 10] },
  DenEncounter { species: types::Species::Qwilfish, flawless_ivs: 4, probabilities: [0, 0, 0, 20, 35] },
  DenEncounter { species: types::Species::Quagsire, flawless_ivs: 4, probabilities: [0, 0, 0, 40, 35] },
  DenEncounter { species: types::Species::Araquanid, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 10] },
  DenEncounter { species: types::Species::Gyarados, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 10] },
];

#[rustfmt::skip]
const NEST_BA8A496710180833: DenEncounters = [
  DenEncounter { species: types::Species::Mantyke, flawless_ivs: 1, probabilities: [68, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Remoraid, flawless_ivs: 1, probabilities: [2, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Wailmer, flawless_ivs: 1, probabilities: [20, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Binacle, flawless_ivs: 1, probabilities: [10, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Krabby, flawless_ivs: 2, probabilities: [0, 20, 20, 0, 0] },
  DenEncounter { species: types::Species::Pyukumuku, flawless_ivs: 2, probabilities: [0, 20, 40, 0, 0] },
  DenEncounter { species: types::Species::Kingler, flawless_ivs: 3, probabilities: [0, 0, 20, 20, 0] },
  DenEncounter { species: types::Species::Basculin, flawless_ivs: 4, probabilities: [0, 0, 20, 20, 10] },
  DenEncounter { species: types::Species::Qwilfish, flawless_ivs: 4, probabilities: [0, 0, 0, 20, 35] },
  DenEncounter { species: types::Species::Octillery, flawless_ivs: 4, probabilities: [0, 0, 0, 40, 35] },
  DenEncounter { species: types::Species::Wailord, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 10] },
  DenEncounter { species: types::Species::Mantine, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 10] },
];

#[rustfmt::skip]
const NEST_4500A0D99CF571B7: DenEncounters = [
  DenEncounter { species: types::Species::Vulpix, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Sizzlipede, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Litwick, flawless_ivs: 1, probabilities: [20, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Charmander, flawless_ivs: 1, probabilities: [10, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Charmeleon, flawless_ivs: 2, probabilities: [0, 20, 20, 0, 0] },
  DenEncounter { species: types::Species::Ninetales, flawless_ivs: 2, probabilities: [0, 20, 40, 0, 0] },
  DenEncounter { species: types::Species::Heatmor, flawless_ivs: 3, probabilities: [0, 0, 20, 20, 0] },
  DenEncounter { species: types::Species::Torkoal, flawless_ivs: 4, probabilities: [0, 0, 20, 20, 20] },
  DenEncounter { species: types::Species::Ninetales, flawless_ivs: 4, probabilities: [0, 0, 0, 20, 30] },
  DenEncounter { species: types::Species::Salazzle, flawless_ivs: 4, probabilities: [0, 0, 0, 40, 30] },
  DenEncounter { species: types::Species::Centiskorch, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Charizard, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 5] },
];

#[rustfmt::skip]
const NEST_4500A1D99CF5736A: DenEncounters = [
  DenEncounter { species: types::Species::Magikarp, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Arrokuda, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Chewtle, flawless_ivs: 1, probabilities: [20, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Krabby, flawless_ivs: 1, probabilities: [10, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Pyukumuku, flawless_ivs: 2, probabilities: [0, 20, 20, 0, 0] },
  DenEncounter { species: types::Species::Basculin, flawless_ivs: 2, probabilities: [0, 20, 40, 0, 0] },
  DenEncounter { species: types::Species::Qwilfish, flawless_ivs: 3, probabilities: [0, 0, 20, 20, 0] },
  DenEncounter { species: types::Species::Kingler, flawless_ivs: 4, probabilities: [0, 0, 20, 20, 20] },
  DenEncounter { species: types::Species::Wishiwashi, flawless_ivs: 4, probabilities: [0, 0, 0, 20, 30] },
  DenEncounter { species: types::Species::Gyarados, flawless_ivs: 4, probabilities: [0, 0, 0, 40, 30] },
  DenEncounter { species: types::Species::Gastrodon, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Drednaw, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 5] },
];

#[rustfmt::skip]
const NEST_4500A2D99CF5751D: DenEncounters = [
  DenEncounter { species: types::Species::Budew, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Seedot, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Gossifleur, flawless_ivs: 1, probabilities: [20, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Ferroseed, flawless_ivs: 1, probabilities: [10, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Nuzleaf, flawless_ivs: 2, probabilities: [0, 20, 20, 0, 0] },
  DenEncounter { species: types::Species::Applin, flawless_ivs: 2, probabilities: [0, 20, 40, 0, 0] },
  DenEncounter { species: types::Species::Roselia, flawless_ivs: 4, probabilities: [0, 0, 20, 20, 10] },
  DenEncounter { species: types::Species::Shiftry, flawless_ivs: 4, probabilities: [0, 0, 20, 20, 20] },
  DenEncounter { species: types::Species::Eldegoss, flawless_ivs: 4, probabilities: [0, 0, 0, 20, 25] },
  DenEncounter { species: types::Species::Ferrothorn, flawless_ivs: 4, probabilities: [0, 0, 0, 40, 25] },
  DenEncounter { species: types::Species::Roserade, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Flapple, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 5] },
];

#[rustfmt::skip]
const NEST_45009BD99CF56938: DenEncounters = [
  DenEncounter { species: types::Species::Vulpix, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Sizzlipede, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Litwick, flawless_ivs: 1, probabilities: [20, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Salandit, flawless_ivs: 1, probabilities: [10, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Carkol, flawless_ivs: 2, probabilities: [0, 20, 20, 0, 0] },
  DenEncounter { species: types::Species::Lampent, flawless_ivs: 2, probabilities: [0, 20, 40, 0, 0] },
  DenEncounter { species: types::Species::Heatmor, flawless_ivs: 3, probabilities: [0, 0, 20, 20, 0] },
  DenEncounter { species: types::Species::Torkoal, flawless_ivs: 4, probabilities: [0, 0, 20, 20, 10] },
  DenEncounter { species: types::Species::Ninetales, flawless_ivs: 4, probabilities: [0, 0, 0, 20, 35] },
  DenEncounter { species: types::Species::Chandelure, flawless_ivs: 4, probabilities: [0, 0, 0, 40, 35] },
  DenEncounter { species: types::Species::Coalossal, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Centiskorch, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 5] },
];

#[rustfmt::skip]
const NEST_45009CD99CF56AEB: DenEncounters = [
  DenEncounter { species: types::Species::Riolu, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Machop, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Stufful, flawless_ivs: 1, probabilities: [20, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::FarfetchD, flawless_ivs: 1, probabilities: [10, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Bewear, flawless_ivs: 2, probabilities: [0, 20, 20, 0, 0] },
  DenEncounter { species: types::Species::Machoke, flawless_ivs: 3, probabilities: [0, 20, 40, 10, 0] },
  DenEncounter { species: types::Species::Falinks, flawless_ivs: 3, probabilities: [0, 0, 20, 10, 0] },
  DenEncounter { species: types::Species::Hawlucha, flawless_ivs: 4, probabilities: [0, 0, 20, 20, 30] },
  DenEncounter { species: types::Species::Lucario, flawless_ivs: 4, probabilities: [0, 0, 0, 20, 39] },
  DenEncounter { species: types::Species::Gallade, flawless_ivs: 4, probabilities: [0, 0, 0, 40, 25] },
  DenEncounter { species: types::Species::SirfetchD, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 1] },
  DenEncounter { species: types::Species::Machamp, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 5] },
];

#[rustfmt::skip]
const NEST_45009DD99CF56C9E: DenEncounters = [
  DenEncounter { species: types::Species::Togepi, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Morelull, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Impidimp, flawless_ivs: 1, probabilities: [20, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Ralts, flawless_ivs: 1, probabilities: [10, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Togetic, flawless_ivs: 2, probabilities: [0, 20, 20, 0, 0] },
  DenEncounter { species: types::Species::Shiinotic, flawless_ivs: 2, probabilities: [0, 20, 40, 0, 0] },
  DenEncounter { species: types::Species::Morgrem, flawless_ivs: 3, probabilities: [0, 0, 20, 20, 0] },
  DenEncounter { species: types::Species::Mawile, flawless_ivs: 4, probabilities: [0, 0, 20, 20, 10] },
  DenEncounter { species: types::Species::Gardevoir, flawless_ivs: 4, probabilities: [0, 0, 0, 20, 35] },
  DenEncounter { species: types::Species::Togekiss, flawless_ivs: 4, probabilities: [0, 0, 0, 40, 35] },
  DenEncounter { species: types::Species::Grimmsnarl, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Alcremie, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 5] },
];

#[rustfmt::skip]
const NEST_45009ED99CF56E51: DenEncounters = [
  DenEncounter { species: types::Species::Dwebble, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Bonsly, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Rolycoly, flawless_ivs: 1, probabilities: [20, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Binacle, flawless_ivs: 1, probabilities: [10, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Carkol, flawless_ivs: 2, probabilities: [0, 20, 20, 0, 0] },
  DenEncounter { species: types::Species::Sudowoodo, flawless_ivs: 2, probabilities: [0, 20, 40, 0, 0] },
  DenEncounter { species: types::Species::Barbaracle, flawless_ivs: 3, probabilities: [0, 0, 20, 20, 0] },
  DenEncounter { species: types::Species::Onix, flawless_ivs: 4, probabilities: [0, 0, 20, 20, 10] },
  DenEncounter { species: types::Species::Crustle, flawless_ivs: 4, probabilities: [0, 0, 0, 20, 35] },
  DenEncounter { species: types::Species::Steelix, flawless_ivs: 4, probabilities: [0, 0, 0, 40, 35] },
  DenEncounter { species: types::Species::Stonjourner, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Coalossal, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 5] },
];

#[rustfmt::skip]
const NEST_450097D99CF5626C: DenEncounters = [
  DenEncounter { species: types::Species::Riolu, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Bronzor, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Pawniard, flawless_ivs: 1, probabilities: [20, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Klink, flawless_ivs: 1, probabilities: [10, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Onix, flawless_ivs: 2, probabilities: [0, 20, 20, 0, 0] },
  DenEncounter { species: types::Species::Durant, flawless_ivs: 2, probabilities: [0, 20, 40, 0, 0] },
  DenEncounter { species: types::Species::Klang, flawless_ivs: 3, probabilities: [0, 0, 20, 20, 0] },
  DenEncounter { species: types::Species::Bronzong, flawless_ivs: 4, probabilities: [0, 0, 20, 20, 10] },
  DenEncounter { species: types::Species::Bisharp, flawless_ivs: 4, probabilities: [0, 0, 0, 20, 35] },
  DenEncounter { species: types::Species::Steelix, flawless_ivs: 4, probabilities: [0, 0, 0, 40, 35] },
  DenEncounter { species: types::Species::Klinklang, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Duraludon, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 5] },
];

#[rustfmt::skip]
const NEST_450098D99CF5641F: DenEncounters = [
  DenEncounter { species: types::Species::Meowth, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Bronzor, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Pawniard, flawless_ivs: 1, probabilities: [20, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Ferroseed, flawless_ivs: 1, probabilities: [10, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Honedge, flawless_ivs: 2, probabilities: [0, 20, 20, 0, 0] },
  DenEncounter { species: types::Species::Bronzong, flawless_ivs: 2, probabilities: [0, 20, 40, 0, 0] },
  DenEncounter { species: types::Species::Perrserker, flawless_ivs: 3, probabilities: [0, 0, 20, 20, 0] },
  DenEncounter { species: types::Species::Ferrothorn, flawless_ivs: 4, probabilities: [0, 0, 20, 20, 10] },
  DenEncounter { species: types::Species::Bisharp, flawless_ivs: 4, probabilities: [0, 0, 0, 20, 35] },
  DenEncounter { species: types::Species::Stunfisk, flawless_ivs: 4, probabilities: [0, 0, 0, 40, 35] },
  DenEncounter { species: types::Species::Duraludon, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Copperajah, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 5] },
];

#[rustfmt::skip]
const NEST_450425D99CF8898D: DenEncounters = [
  DenEncounter { species: types::Species::Stunky, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Trubbish, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Skorupi, flawless_ivs: 1, probabilities: [20, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Koffing, flawless_ivs: 1, probabilities: [10, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Mareanie, flawless_ivs: 2, probabilities: [0, 20, 20, 0, 0] },
  DenEncounter { species: types::Species::Toxel, flawless_ivs: 2, probabilities: [0, 20, 40, 0, 0] },
  DenEncounter { species: types::Species::Drapion, flawless_ivs: 3, probabilities: [0, 0, 20, 20, 0] },
  DenEncounter { species: types::Species::Toxtricity, flawless_ivs: 4, probabilities: [0, 0, 20, 20, 10] },
  DenEncounter { species: types::Species::Skuntank, flawless_ivs: 4, probabilities: [0, 0, 0, 20, 35] },
  DenEncounter { species: types::Species::Weezing, flawless_ivs: 4, probabilities: [0, 0, 0, 40, 35] },
  DenEncounter { species: types::Species::Toxapex, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Garbodor, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 5] },
];

#[rustfmt::skip]
const NEST_450424D99CF887DA: DenEncounters = [
  DenEncounter { species: types::Species::Togepi, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Swirlix, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Impidimp, flawless_ivs: 1, probabilities: [20, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Ralts, flawless_ivs: 1, probabilities: [10, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Togetic, flawless_ivs: 2, probabilities: [0, 20, 20, 0, 0] },
  DenEncounter { species: types::Species::Morgrem, flawless_ivs: 2, probabilities: [0, 20, 40, 0, 0] },
  DenEncounter { species: types::Species::Slurpuff, flawless_ivs: 3, probabilities: [0, 0, 20, 20, 0] },
  DenEncounter { species: types::Species::Milcery, flawless_ivs: 4, probabilities: [0, 0, 20, 20, 10] },
  DenEncounter { species: types::Species::Gardevoir, flawless_ivs: 4, probabilities: [0, 0, 0, 20, 35] },
  DenEncounter { species: types::Species::Grimmsnarl, flawless_ivs: 4, probabilities: [0, 0, 0, 40, 35] },
  DenEncounter { species: types::Species::Togekiss, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Hatterene, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 5] },
];

#[rustfmt::skip]
const NEST_450423D99CF88627: DenEncounters = [
  DenEncounter { species: types::Species::Nickit, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Zigzagoon, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Scraggy, flawless_ivs: 1, probabilities: [20, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Impidimp, flawless_ivs: 1, probabilities: [10, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Liepard, flawless_ivs: 2, probabilities: [0, 20, 20, 0, 0] },
  DenEncounter { species: types::Species::Linoone, flawless_ivs: 2, probabilities: [0, 20, 40, 0, 0] },
  DenEncounter { species: types::Species::Morgrem, flawless_ivs: 3, probabilities: [0, 0, 20, 20, 0] },
  DenEncounter { species: types::Species::Thievul, flawless_ivs: 4, probabilities: [0, 0, 20, 20, 10] },
  DenEncounter { species: types::Species::Pangoro, flawless_ivs: 4, probabilities: [0, 0, 0, 20, 35] },
  DenEncounter { species: types::Species::Scrafty, flawless_ivs: 4, probabilities: [0, 0, 0, 40, 35] },
  DenEncounter { species: types::Species::Hydreigon, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Grimmsnarl, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 5] },
];

#[rustfmt::skip]
const NEST_450422D99CF88474: DenEncounters = [
  DenEncounter { species: types::Species::Natu, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Hoothoot, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Rookidee, flawless_ivs: 1, probabilities: [20, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Wingull, flawless_ivs: 1, probabilities: [10, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Butterfree, flawless_ivs: 2, probabilities: [0, 20, 20, 0, 0] },
  DenEncounter { species: types::Species::Corvisquire, flawless_ivs: 2, probabilities: [0, 20, 40, 0, 0] },
  DenEncounter { species: types::Species::Noctowl, flawless_ivs: 3, probabilities: [0, 0, 20, 25, 0] },
  DenEncounter { species: types::Species::Pelipper, flawless_ivs: 4, probabilities: [0, 0, 20, 20, 10] },
  DenEncounter { species: types::Species::Xatu, flawless_ivs: 4, probabilities: [0, 0, 0, 20, 35] },
  DenEncounter { species: types::Species::Hawlucha, flawless_ivs: 4, probabilities: [0, 0, 0, 35, 35] },
  DenEncounter { species: types::Species::Sigilyph, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Corviknight, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 5] },
];

#[rustfmt::skip]
const NEST_450421D99CF882C1: DenEncounters = [
  DenEncounter { species: types::Species::Wimpod, flawless_ivs: 1, probabilities: [30, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Blipbug, flawless_ivs: 1, probabilities: [20, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Karrablast, flawless_ivs: 1, probabilities: [20, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Dewpider, flawless_ivs: 1, probabilities: [20, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Shelmet, flawless_ivs: 2, probabilities: [0, 20, 20, 0, 0] },
  DenEncounter { species: types::Species::Dwebble, flawless_ivs: 2, probabilities: [0, 20, 30, 0, 0] },
  DenEncounter { species: types::Species::Dottler, flawless_ivs: 3, probabilities: [0, 0, 20, 20, 0] },
  DenEncounter { species: types::Species::Orbeetle, flawless_ivs: 4, probabilities: [0, 0, 20, 20, 20] },
  DenEncounter { species: types::Species::Araquanid, flawless_ivs: 4, probabilities: [0, 0, 0, 20, 25] },
  DenEncounter { species: types::Species::Golisopod, flawless_ivs: 4, probabilities: [0, 0, 0, 30, 30] },
  DenEncounter { species: types::Species::Escavalier, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Butterfree, flawless_ivs: 4, probabilities: [10, 10, 10, 10, 10] },
];

#[rustfmt::skip]
const NEST_450420D99CF8810E: DenEncounters = [
  DenEncounter { species: types::Species::Corphish, flawless_ivs: 1, probabilities: [40, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Krabby, flawless_ivs: 1, probabilities: [25, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Arrokuda, flawless_ivs: 1, probabilities: [25, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Chewtle, flawless_ivs: 1, probabilities: [10, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Mareanie, flawless_ivs: 2, probabilities: [0, 20, 20, 0, 0] },
  DenEncounter { species: types::Species::Basculin, flawless_ivs: 2, probabilities: [0, 20, 30, 0, 0] },
  DenEncounter { species: types::Species::Crawdaunt, flawless_ivs: 3, probabilities: [0, 0, 20, 20, 0] },
  DenEncounter { species: types::Species::Toxapex, flawless_ivs: 4, probabilities: [0, 0, 20, 20, 15] },
  DenEncounter { species: types::Species::Pyukumuku, flawless_ivs: 4, probabilities: [0, 0, 0, 20, 25] },
  DenEncounter { species: types::Species::Gyarados, flawless_ivs: 4, probabilities: [0, 0, 0, 30, 35] },
  DenEncounter { species: types::Species::Lapras, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Kingler, flawless_ivs: 4, probabilities: [0, 10, 10, 10, 10] },
];

#[rustfmt::skip]
const NEST_45041FD99CF87F5B: DenEncounters = [
  DenEncounter { species: types::Species::Wimpod, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Blipbug, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Karrablast, flawless_ivs: 1, probabilities: [20, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Dewpider, flawless_ivs: 1, probabilities: [10, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Shelmet, flawless_ivs: 2, probabilities: [0, 20, 20, 0, 0] },
  DenEncounter { species: types::Species::Dwebble, flawless_ivs: 2, probabilities: [0, 20, 30, 0, 0] },
  DenEncounter { species: types::Species::Dottler, flawless_ivs: 3, probabilities: [0, 0, 20, 20, 0] },
  DenEncounter { species: types::Species::Orbeetle, flawless_ivs: 4, probabilities: [0, 0, 20, 20, 20] },
  DenEncounter { species: types::Species::Araquanid, flawless_ivs: 4, probabilities: [0, 0, 0, 20, 25] },
  DenEncounter { species: types::Species::Golisopod, flawless_ivs: 4, probabilities: [0, 0, 0, 30, 30] },
  DenEncounter { species: types::Species::Escavalier, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Orbeetle, flawless_ivs: 4, probabilities: [0, 0, 10, 10, 10] },
];

#[rustfmt::skip]
const NEST_45041ED99CF87DA8: DenEncounters = [
  DenEncounter { species: types::Species::Wooper, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Barboach, flawless_ivs: 1, probabilities: [35, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Yamask, flawless_ivs: 1, probabilities: [20, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Golett, flawless_ivs: 1, probabilities: [10, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Palpitoad, flawless_ivs: 2, probabilities: [0, 20, 20, 0, 0] },
  DenEncounter { species: types::Species::Quagsire, flawless_ivs: 2, probabilities: [0, 20, 40, 0, 0] },
  DenEncounter { species: types::Species::Stunfisk, flawless_ivs: 3, probabilities: [0, 0, 20, 20, 0] },
  DenEncounter { species: types::Species::Golurk, flawless_ivs: 4, probabilities: [0, 0, 20, 20, 20] },
  DenEncounter { species: types::Species::Gastrodon, flawless_ivs: 4, probabilities: [0, 0, 0, 20, 25] },
  DenEncounter { species: types::Species::Seismitoad, flawless_ivs: 4, probabilities: [0, 0, 0, 30, 30] },
  DenEncounter { species: types::Species::Rhyperior, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Sandaconda, flawless_ivs: 4, probabilities: [0, 0, 0, 10, 10] },
];

#[rustfmt::skip]
const NEST_21F6C965B3513D5E: DenEncounters = [
  DenEncounter { species: types::Species::Chansey, flawless_ivs: 4, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Igglybuff, flawless_ivs: 1, probabilities: [60, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Lillipup, flawless_ivs: 1, probabilities: [40, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Buneary, flawless_ivs: 2, probabilities: [0, 25, 30, 0, 0] },
  DenEncounter { species: types::Species::Jigglypuff, flawless_ivs: 2, probabilities: [0, 20, 25, 0, 0] },
  DenEncounter { species: types::Species::Jigglypuff, flawless_ivs: 3, probabilities: [0, 0, 25, 25, 0] },
  DenEncounter { species: types::Species::Herdier, flawless_ivs: 3, probabilities: [0, 0, 15, 25, 0] },
  DenEncounter { species: types::Species::Lopunny, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 25] },
  DenEncounter { species: types::Species::Lopunny, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Wigglytuff, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Dunsparce, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Stoutland, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
];

#[rustfmt::skip]
const NEST_D8F100CDE5822516: DenEncounters = [
  DenEncounter { species: types::Species::Blissey, flawless_ivs: 4, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Lillipup, flawless_ivs: 1, probabilities: [60, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Stufful, flawless_ivs: 1, probabilities: [40, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Jigglypuff, flawless_ivs: 2, probabilities: [0, 25, 30, 0, 0] },
  DenEncounter { species: types::Species::Buneary, flawless_ivs: 2, probabilities: [0, 20, 25, 0, 0] },
  DenEncounter { species: types::Species::Jigglypuff, flawless_ivs: 3, probabilities: [0, 0, 25, 25, 0] },
  DenEncounter { species: types::Species::Dunsparce, flawless_ivs: 3, probabilities: [0, 0, 15, 25, 0] },
  DenEncounter { species: types::Species::Dubwool, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Lopunny, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Stoutland, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Bewear, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 20] },
  DenEncounter { species: types::Species::Wigglytuff, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
];

#[rustfmt::skip]
const NEST_21F6C865B3513BAB: DenEncounters = [
  DenEncounter { species: types::Species::Chansey, flawless_ivs: 4, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Whismur, flawless_ivs: 1, probabilities: [60, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Lickitung, flawless_ivs: 1, probabilities: [40, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Miltank, flawless_ivs: 2, probabilities: [0, 25, 30, 0, 0] },
  DenEncounter { species: types::Species::Loudred, flawless_ivs: 2, probabilities: [0, 20, 25, 0, 0] },
  DenEncounter { species: types::Species::Loudred, flawless_ivs: 3, probabilities: [0, 0, 25, 25, 0] },
  DenEncounter { species: types::Species::Lickitung, flawless_ivs: 3, probabilities: [0, 0, 15, 25, 0] },
  DenEncounter { species: types::Species::Miltank, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 25] },
  DenEncounter { species: types::Species::Bouffalant, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Tauros, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Exploud, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Lickilicky, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
];

#[rustfmt::skip]
const NEST_D8F0FFCDE5822363: DenEncounters = [
  DenEncounter { species: types::Species::Blissey, flawless_ivs: 4, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Whismur, flawless_ivs: 1, probabilities: [60, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Tauros, flawless_ivs: 1, probabilities: [40, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Lickitung, flawless_ivs: 2, probabilities: [0, 25, 30, 0, 0] },
  DenEncounter { species: types::Species::Miltank, flawless_ivs: 2, probabilities: [0, 20, 25, 0, 0] },
  DenEncounter { species: types::Species::Miltank, flawless_ivs: 3, probabilities: [0, 0, 25, 25, 0] },
  DenEncounter { species: types::Species::Bouffalant, flawless_ivs: 3, probabilities: [0, 0, 15, 25, 0] },
  DenEncounter { species: types::Species::Tauros, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Exploud, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Cinccino, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Exploud, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 20] },
  DenEncounter { species: types::Species::Lickilicky, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
];

#[rustfmt::skip]
const NEST_60EF1D711AE30CF0: DenEncounters = [
  DenEncounter { species: types::Species::Chansey, flawless_ivs: 4, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Sandshrew, flawless_ivs: 1, probabilities: [60, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Sandile, flawless_ivs: 1, probabilities: [40, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Cubone, flawless_ivs: 2, probabilities: [0, 25, 30, 0, 0] },
  DenEncounter { species: types::Species::Sandshrew, flawless_ivs: 2, probabilities: [0, 20, 25, 0, 0] },
  DenEncounter { species: types::Species::Krokorok, flawless_ivs: 3, probabilities: [0, 0, 25, 25, 0] },
  DenEncounter { species: types::Species::Sandslash, flawless_ivs: 3, probabilities: [0, 0, 15, 25, 0] },
  DenEncounter { species: types::Species::Sandaconda, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 25] },
  DenEncounter { species: types::Species::Sandslash, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Marowak, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Krookodile, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Kangaskhan, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
];

#[rustfmt::skip]
const NEST_C80756327D5DE060: DenEncounters = [
  DenEncounter { species: types::Species::Blissey, flawless_ivs: 4, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Sandshrew, flawless_ivs: 1, probabilities: [60, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Cubone, flawless_ivs: 1, probabilities: [40, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Trapinch, flawless_ivs: 2, probabilities: [0, 25, 30, 0, 0] },
  DenEncounter { species: types::Species::Trapinch, flawless_ivs: 2, probabilities: [0, 20, 25, 0, 0] },
  DenEncounter { species: types::Species::Krokorok, flawless_ivs: 3, probabilities: [0, 0, 25, 25, 0] },
  DenEncounter { species: types::Species::Sandslash, flawless_ivs: 3, probabilities: [0, 0, 15, 25, 0] },
  DenEncounter { species: types::Species::Marowak, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Krookodile, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Kangaskhan, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Flygon, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 20] },
  DenEncounter { species: types::Species::Golurk, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
];

#[rustfmt::skip]
const NEST_6E6B46639F77F0C8: DenEncounters = [
  DenEncounter { species: types::Species::Chansey, flawless_ivs: 4, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Dedenne, flawless_ivs: 1, probabilities: [60, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Magnemite, flawless_ivs: 1, probabilities: [40, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Shinx, flawless_ivs: 2, probabilities: [0, 25, 30, 0, 0] },
  DenEncounter { species: types::Species::Morpeko, flawless_ivs: 2, probabilities: [0, 20, 25, 0, 0] },
  DenEncounter { species: types::Species::Dedenne, flawless_ivs: 3, probabilities: [0, 0, 25, 25, 0] },
  DenEncounter { species: types::Species::Luxio, flawless_ivs: 3, probabilities: [0, 0, 15, 25, 0] },
  DenEncounter { species: types::Species::Dedenne, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 25] },
  DenEncounter { species: types::Species::Magneton, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Pincurchin, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Luxray, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Magnezone, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
];

#[rustfmt::skip]
const NEST_1C1962488C012EE8: DenEncounters = [
  DenEncounter { species: types::Species::Blissey, flawless_ivs: 4, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Shinx, flawless_ivs: 1, probabilities: [60, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Pichu, flawless_ivs: 1, probabilities: [40, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Pikachu, flawless_ivs: 2, probabilities: [0, 25, 30, 0, 0] },
  DenEncounter { species: types::Species::Pincurchin, flawless_ivs: 2, probabilities: [0, 20, 25, 0, 0] },
  DenEncounter { species: types::Species::Luxio, flawless_ivs: 3, probabilities: [0, 0, 25, 25, 0] },
  DenEncounter { species: types::Species::Raichu, flawless_ivs: 3, probabilities: [0, 0, 15, 25, 0] },
  DenEncounter { species: types::Species::Boltund, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Dedenne, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Manectric, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Luxray, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 20] },
  DenEncounter { species: types::Species::Magnezone, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
];

#[rustfmt::skip]
const NEST_A178D4769765ABAC: DenEncounters = [
  DenEncounter { species: types::Species::Chansey, flawless_ivs: 4, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Fletchling, flawless_ivs: 1, probabilities: [60, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Woobat, flawless_ivs: 1, probabilities: [40, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Rufflet, flawless_ivs: 2, probabilities: [0, 25, 30, 0, 0] },
  DenEncounter { species: types::Species::Emolga, flawless_ivs: 2, probabilities: [0, 20, 25, 0, 0] },
  DenEncounter { species: types::Species::Fletchinder, flawless_ivs: 3, probabilities: [0, 0, 25, 25, 0] },
  DenEncounter { species: types::Species::Fletchinder, flawless_ivs: 3, probabilities: [0, 0, 15, 25, 0] },
  DenEncounter { species: types::Species::Braviary, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 25] },
  DenEncounter { species: types::Species::Emolga, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Swoobat, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Braviary, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Talonflame, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
];

#[rustfmt::skip]
const NEST_F4A830850F51D034: DenEncounters = [
  DenEncounter { species: types::Species::Blissey, flawless_ivs: 4, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Hoothoot, flawless_ivs: 1, probabilities: [60, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Pidove, flawless_ivs: 1, probabilities: [40, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Rufflet, flawless_ivs: 2, probabilities: [0, 25, 30, 0, 0] },
  DenEncounter { species: types::Species::Tranquill, flawless_ivs: 2, probabilities: [0, 20, 25, 0, 0] },
  DenEncounter { species: types::Species::Swoobat, flawless_ivs: 3, probabilities: [0, 0, 25, 25, 0] },
  DenEncounter { species: types::Species::Noctowl, flawless_ivs: 3, probabilities: [0, 0, 15, 25, 0] },
  DenEncounter { species: types::Species::Unfezant, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Talonflame, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Emolga, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Braviary, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 20] },
  DenEncounter { species: types::Species::Talonflame, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
];

#[rustfmt::skip]
const NEST_6D015B7858EB5119: DenEncounters = [
  DenEncounter { species: types::Species::Chansey, flawless_ivs: 4, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Pinsir, flawless_ivs: 1, probabilities: [60, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Dwebble, flawless_ivs: 1, probabilities: [40, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Dottler, flawless_ivs: 2, probabilities: [0, 25, 30, 0, 0] },
  DenEncounter { species: types::Species::Pinsir, flawless_ivs: 2, probabilities: [0, 20, 25, 0, 0] },
  DenEncounter { species: types::Species::Pinsir, flawless_ivs: 3, probabilities: [0, 0, 25, 25, 0] },
  DenEncounter { species: types::Species::Crustle, flawless_ivs: 3, probabilities: [0, 0, 15, 25, 0] },
  DenEncounter { species: types::Species::Scyther, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 25] },
  DenEncounter { species: types::Species::Scyther, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Pinsir, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Orbeetle, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Scizor, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
];

#[rustfmt::skip]
const NEST_53441B80E563EF1F: DenEncounters = [
  DenEncounter { species: types::Species::Blissey, flawless_ivs: 4, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Scyther, flawless_ivs: 1, probabilities: [60, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Pinsir, flawless_ivs: 1, probabilities: [40, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Shuckle, flawless_ivs: 2, probabilities: [0, 25, 30, 0, 0] },
  DenEncounter { species: types::Species::Whirlipede, flawless_ivs: 2, probabilities: [0, 20, 25, 0, 0] },
  DenEncounter { species: types::Species::Scyther, flawless_ivs: 3, probabilities: [0, 0, 25, 25, 0] },
  DenEncounter { species: types::Species::Crustle, flawless_ivs: 3, probabilities: [0, 0, 15, 25, 0] },
  DenEncounter { species: types::Species::Scolipede, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Accelgor, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Escavalier, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Pinsir, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 20] },
  DenEncounter { species: types::Species::Scizor, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
];

#[rustfmt::skip]
const NEST_2998F2424D0353EB: DenEncounters = [
  DenEncounter { species: types::Species::Chansey, flawless_ivs: 4, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Foongus, flawless_ivs: 1, probabilities: [60, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Fomantis, flawless_ivs: 1, probabilities: [40, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Petilil, flawless_ivs: 2, probabilities: [0, 25, 30, 0, 0] },
  DenEncounter { species: types::Species::Lurantis, flawless_ivs: 2, probabilities: [0, 20, 25, 0, 0] },
  DenEncounter { species: types::Species::Amoonguss, flawless_ivs: 3, probabilities: [0, 0, 25, 25, 0] },
  DenEncounter { species: types::Species::Tangela, flawless_ivs: 3, probabilities: [0, 0, 15, 25, 0] },
  DenEncounter { species: types::Species::Lilligant, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 25] },
  DenEncounter { species: types::Species::Lurantis, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Lilligant, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Amoonguss, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Tangrowth, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
];

#[rustfmt::skip]
const NEST_AE57B2A84974C3A1: DenEncounters = [
  DenEncounter { species: types::Species::Blissey, flawless_ivs: 4, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Tangela, flawless_ivs: 1, probabilities: [60, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Fomantis, flawless_ivs: 1, probabilities: [40, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Foongus, flawless_ivs: 2, probabilities: [0, 25, 30, 0, 0] },
  DenEncounter { species: types::Species::Lurantis, flawless_ivs: 2, probabilities: [0, 20, 25, 0, 0] },
  DenEncounter { species: types::Species::Maractus, flawless_ivs: 3, probabilities: [0, 0, 25, 25, 0] },
  DenEncounter { species: types::Species::Lilligant, flawless_ivs: 3, probabilities: [0, 0, 15, 25, 0] },
  DenEncounter { species: types::Species::Lurantis, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Amoonguss, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Tangrowth, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Lilligant, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 20] },
  DenEncounter { species: types::Species::Abomasnow, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
];

#[rustfmt::skip]
const NEST_5B72BFAC0FF3F885: DenEncounters = [
  DenEncounter { species: types::Species::Chansey, flawless_ivs: 4, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Fletchling, flawless_ivs: 1, probabilities: [60, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Salandit, flawless_ivs: 1, probabilities: [40, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Larvesta, flawless_ivs: 2, probabilities: [0, 25, 30, 0, 0] },
  DenEncounter { species: types::Species::Salandit, flawless_ivs: 2, probabilities: [0, 20, 25, 0, 0] },
  DenEncounter { species: types::Species::Fletchinder, flawless_ivs: 3, probabilities: [0, 0, 25, 25, 0] },
  DenEncounter { species: types::Species::Larvesta, flawless_ivs: 3, probabilities: [0, 0, 15, 25, 0] },
  DenEncounter { species: types::Species::Torkoal, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 25] },
  DenEncounter { species: types::Species::Talonflame, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Salazzle, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Torkoal, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Volcarona, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
];

#[rustfmt::skip]
const NEST_316E6B5E74BC7AA3: DenEncounters = [
  DenEncounter { species: types::Species::Blissey, flawless_ivs: 4, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Larvesta, flawless_ivs: 1, probabilities: [60, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Litwick, flawless_ivs: 1, probabilities: [40, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Larvesta, flawless_ivs: 2, probabilities: [0, 25, 30, 0, 0] },
  DenEncounter { species: types::Species::Salandit, flawless_ivs: 2, probabilities: [0, 20, 25, 0, 0] },
  DenEncounter { species: types::Species::Torkoal, flawless_ivs: 3, probabilities: [0, 0, 25, 25, 0] },
  DenEncounter { species: types::Species::Salazzle, flawless_ivs: 3, probabilities: [0, 0, 15, 25, 0] },
  DenEncounter { species: types::Species::Talonflame, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Chandelure, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Volcarona, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Ninetales, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 20] },
  DenEncounter { species: types::Species::Charizard, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
];

#[rustfmt::skip]
const NEST_79B25A4F80255A38: DenEncounters = [
  DenEncounter { species: types::Species::Chansey, flawless_ivs: 4, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Roggenrola, flawless_ivs: 1, probabilities: [60, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Rhyhorn, flawless_ivs: 1, probabilities: [40, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Rockruff, flawless_ivs: 2, probabilities: [0, 25, 30, 0, 0] },
  DenEncounter { species: types::Species::Boldore, flawless_ivs: 2, probabilities: [0, 20, 25, 0, 0] },
  DenEncounter { species: types::Species::Rhydon, flawless_ivs: 3, probabilities: [0, 0, 25, 25, 0] },
  DenEncounter { species: types::Species::Crustle, flawless_ivs: 3, probabilities: [0, 0, 15, 25, 0] },
  DenEncounter { species: types::Species::Rhydon, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 25] },
  DenEncounter { species: types::Species::Gigalith, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Crustle, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Lycanroc, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Rhyperior, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
];

#[rustfmt::skip]
const NEST_C8EA8C1618AB0A58: DenEncounters = [
  DenEncounter { species: types::Species::Blissey, flawless_ivs: 4, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Rockruff, flawless_ivs: 1, probabilities: [60, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Bonsly, flawless_ivs: 1, probabilities: [40, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Rhyhorn, flawless_ivs: 2, probabilities: [0, 25, 30, 0, 0] },
  DenEncounter { species: types::Species::Rockruff, flawless_ivs: 2, probabilities: [0, 20, 25, 0, 0] },
  DenEncounter { species: types::Species::Rhydon, flawless_ivs: 3, probabilities: [0, 0, 25, 25, 0] },
  DenEncounter { species: types::Species::Shuckle, flawless_ivs: 3, probabilities: [0, 0, 15, 25, 0] },
  DenEncounter { species: types::Species::Lycanroc, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Sudowoodo, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Gigalith, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Crustle, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 20] },
  DenEncounter { species: types::Species::Rhyperior, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
];

#[rustfmt::skip]
const NEST_B8A5E528BFEE71BC: DenEncounters = [
  DenEncounter { species: types::Species::Chansey, flawless_ivs: 4, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Exeggcute, flawless_ivs: 1, probabilities: [60, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Abra, flawless_ivs: 1, probabilities: [40, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Ralts, flawless_ivs: 2, probabilities: [0, 25, 30, 0, 0] },
  DenEncounter { species: types::Species::Kadabra, flawless_ivs: 2, probabilities: [0, 20, 25, 0, 0] },
  DenEncounter { species: types::Species::Kirlia, flawless_ivs: 3, probabilities: [0, 0, 25, 25, 0] },
  DenEncounter { species: types::Species::Kadabra, flawless_ivs: 3, probabilities: [0, 0, 15, 25, 0] },
  DenEncounter { species: types::Species::Exeggutor, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 25] },
  DenEncounter { species: types::Species::Gardevoir, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Exeggutor, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Alakazam, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Starmie, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
];

#[rustfmt::skip]
const NEST_DF017F3FEFBA2704: DenEncounters = [
  DenEncounter { species: types::Species::Blissey, flawless_ivs: 4, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Elgyem, flawless_ivs: 1, probabilities: [60, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Abra, flawless_ivs: 1, probabilities: [40, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Slowpoke, flawless_ivs: 2, probabilities: [0, 25, 30, 0, 0] },
  DenEncounter { species: types::Species::Elgyem, flawless_ivs: 2, probabilities: [0, 20, 25, 0, 0] },
  DenEncounter { species: types::Species::Kadabra, flawless_ivs: 3, probabilities: [0, 0, 25, 25, 0] },
  DenEncounter { species: types::Species::Slowpoke, flawless_ivs: 3, probabilities: [0, 0, 15, 25, 0] },
  DenEncounter { species: types::Species::Musharna, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Indeedee, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Beheeyem, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Alakazam, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 20] },
  DenEncounter { species: types::Species::Meowstic, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
];

#[rustfmt::skip]
const NEST_5C9A35CA819B38C8: DenEncounters = [
  DenEncounter { species: types::Species::Chansey, flawless_ivs: 4, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Venipede, flawless_ivs: 1, probabilities: [60, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Skorupi, flawless_ivs: 1, probabilities: [40, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Tentacool, flawless_ivs: 2, probabilities: [0, 25, 30, 0, 0] },
  DenEncounter { species: types::Species::Tentacool, flawless_ivs: 2, probabilities: [0, 20, 25, 0, 0] },
  DenEncounter { species: types::Species::Whirlipede, flawless_ivs: 3, probabilities: [0, 0, 25, 25, 0] },
  DenEncounter { species: types::Species::Whirlipede, flawless_ivs: 3, probabilities: [0, 0, 15, 25, 0] },
  DenEncounter { species: types::Species::Drapion, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 25] },
  DenEncounter { species: types::Species::Tentacruel, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Drapion, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Tentacruel, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Scolipede, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
];

#[rustfmt::skip]
const NEST_F9222E1ACDF486E8: DenEncounters = [
  DenEncounter { species: types::Species::Blissey, flawless_ivs: 4, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Mareanie, flawless_ivs: 1, probabilities: [60, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Qwilfish, flawless_ivs: 1, probabilities: [40, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Whirlipede, flawless_ivs: 2, probabilities: [0, 25, 30, 0, 0] },
  DenEncounter { species: types::Species::Whirlipede, flawless_ivs: 2, probabilities: [0, 20, 25, 0, 0] },
  DenEncounter { species: types::Species::Qwilfish, flawless_ivs: 3, probabilities: [0, 0, 25, 25, 0] },
  DenEncounter { species: types::Species::Amoonguss, flawless_ivs: 3, probabilities: [0, 0, 15, 25, 0] },
  DenEncounter { species: types::Species::Toxapex, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Scolipede, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Drapion, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Weezing, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 20] },
  DenEncounter { species: types::Species::Scolipede, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
];

#[rustfmt::skip]
const NEST_C63DEC8A65B5C540: DenEncounters = [
  DenEncounter { species: types::Species::Chansey, flawless_ivs: 4, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Carvanha, flawless_ivs: 1, probabilities: [60, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Pawniard, flawless_ivs: 1, probabilities: [40, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Carvanha, flawless_ivs: 2, probabilities: [0, 25, 30, 0, 0] },
  DenEncounter { species: types::Species::Zorua, flawless_ivs: 2, probabilities: [0, 20, 25, 0, 0] },
  DenEncounter { species: types::Species::Sharpedo, flawless_ivs: 3, probabilities: [0, 0, 25, 25, 0] },
  DenEncounter { species: types::Species::Malamar, flawless_ivs: 3, probabilities: [0, 0, 15, 25, 0] },
  DenEncounter { species: types::Species::Drapion, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 25] },
  DenEncounter { species: types::Species::Bisharp, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Malamar, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Sharpedo, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Zoroark, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
];

#[rustfmt::skip]
const NEST_6AEBEE2A2D6D8470: DenEncounters = [
  DenEncounter { species: types::Species::Blissey, flawless_ivs: 4, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Zorua, flawless_ivs: 1, probabilities: [60, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Carvanha, flawless_ivs: 1, probabilities: [40, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Zorua, flawless_ivs: 2, probabilities: [0, 25, 30, 0, 0] },
  DenEncounter { species: types::Species::Inkay, flawless_ivs: 2, probabilities: [0, 20, 25, 0, 0] },
  DenEncounter { species: types::Species::Krokorok, flawless_ivs: 3, probabilities: [0, 0, 25, 25, 0] },
  DenEncounter { species: types::Species::Malamar, flawless_ivs: 3, probabilities: [0, 0, 15, 25, 0] },
  DenEncounter { species: types::Species::Thievul, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Zoroark, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Sharpedo, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Liepard, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 20] },
  DenEncounter { species: types::Species::Krookodile, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
];

#[rustfmt::skip]
const NEST_BC3D01FFF751CDE4: DenEncounters = [
  DenEncounter { species: types::Species::Chansey, flawless_ivs: 4, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Mienfoo, flawless_ivs: 1, probabilities: [60, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Clobbopus, flawless_ivs: 1, probabilities: [40, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Mienfoo, flawless_ivs: 2, probabilities: [0, 25, 30, 0, 0] },
  DenEncounter { species: types::Species::Scraggy, flawless_ivs: 2, probabilities: [0, 20, 25, 0, 0] },
  DenEncounter { species: types::Species::Passimian, flawless_ivs: 3, probabilities: [0, 0, 25, 25, 0] },
  DenEncounter { species: types::Species::Scrafty, flawless_ivs: 3, probabilities: [0, 0, 15, 25, 0] },
  DenEncounter { species: types::Species::Mienshao, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 25] },
  DenEncounter { species: types::Species::Mienshao, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Scrafty, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Grapploct, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Mienshao, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
];

#[rustfmt::skip]
const NEST_6F948F09933CDFC: DenEncounters = [
  DenEncounter { species: types::Species::Blissey, flawless_ivs: 4, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Mienfoo, flawless_ivs: 1, probabilities: [60, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Scraggy, flawless_ivs: 1, probabilities: [40, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Sawk, flawless_ivs: 2, probabilities: [0, 25, 30, 0, 0] },
  DenEncounter { species: types::Species::Mienshao, flawless_ivs: 2, probabilities: [0, 20, 25, 0, 0] },
  DenEncounter { species: types::Species::Falinks, flawless_ivs: 3, probabilities: [0, 0, 25, 25, 0] },
  DenEncounter { species: types::Species::Passimian, flawless_ivs: 3, probabilities: [0, 0, 15, 25, 0] },
  DenEncounter { species: types::Species::Sawk, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Mienshao, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Scrafty, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Grapploct, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 20] },
  DenEncounter { species: types::Species::SirfetchD, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
];

#[rustfmt::skip]
const NEST_E2C6E5E725342F4A: DenEncounters = [
  DenEncounter { species: types::Species::Chansey, flawless_ivs: 4, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Igglybuff, flawless_ivs: 1, probabilities: [60, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Azurill, flawless_ivs: 1, probabilities: [40, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Comfey, flawless_ivs: 2, probabilities: [0, 25, 30, 0, 0] },
  DenEncounter { species: types::Species::Jigglypuff, flawless_ivs: 2, probabilities: [0, 20, 25, 0, 0] },
  DenEncounter { species: types::Species::Marill, flawless_ivs: 3, probabilities: [0, 0, 25, 25, 0] },
  DenEncounter { species: types::Species::Comfey, flawless_ivs: 3, probabilities: [0, 0, 15, 25, 0] },
  DenEncounter { species: types::Species::Klefki, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 25] },
  DenEncounter { species: types::Species::Azumarill, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Wigglytuff, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Gardevoir, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Comfey, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
];

#[rustfmt::skip]
const NEST_89955CC3A594E51A: DenEncounters = [
  DenEncounter { species: types::Species::Blissey, flawless_ivs: 4, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Cleffa, flawless_ivs: 1, probabilities: [60, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Morelull, flawless_ivs: 1, probabilities: [40, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Marill, flawless_ivs: 2, probabilities: [0, 25, 30, 0, 0] },
  DenEncounter { species: types::Species::Clefairy, flawless_ivs: 2, probabilities: [0, 20, 25, 0, 0] },
  DenEncounter { species: types::Species::Kirlia, flawless_ivs: 3, probabilities: [0, 0, 25, 25, 0] },
  DenEncounter { species: types::Species::Klefki, flawless_ivs: 3, probabilities: [0, 0, 15, 25, 0] },
  DenEncounter { species: types::Species::Comfey, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Clefable, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Gardevoir, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Shiinotic, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 20] },
  DenEncounter { species: types::Species::Azumarill, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
];

#[rustfmt::skip]
const NEST_4C12CEE7784C8B8: DenEncounters = [
  DenEncounter { species: types::Species::Chansey, flawless_ivs: 4, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Sandygast, flawless_ivs: 1, probabilities: [60, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Frillish, flawless_ivs: 1, probabilities: [40, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Cubone, flawless_ivs: 2, probabilities: [0, 25, 30, 0, 0] },
  DenEncounter { species: types::Species::Drifloon, flawless_ivs: 2, probabilities: [0, 20, 25, 0, 0] },
  DenEncounter { species: types::Species::Jellicent, flawless_ivs: 3, probabilities: [0, 0, 25, 25, 0] },
  DenEncounter { species: types::Species::Drifblim, flawless_ivs: 3, probabilities: [0, 0, 15, 25, 0] },
  DenEncounter { species: types::Species::Palossand, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 25] },
  DenEncounter { species: types::Species::Jellicent, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Drifblim, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Marowak, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Palossand, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
];

#[rustfmt::skip]
const NEST_7288F0346FD3CDD8: DenEncounters = [
  DenEncounter { species: types::Species::Blissey, flawless_ivs: 4, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Sandygast, flawless_ivs: 1, probabilities: [60, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Frillish, flawless_ivs: 1, probabilities: [40, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Sandygast, flawless_ivs: 2, probabilities: [0, 25, 30, 0, 0] },
  DenEncounter { species: types::Species::Drifloon, flawless_ivs: 2, probabilities: [0, 20, 25, 0, 0] },
  DenEncounter { species: types::Species::Jellicent, flawless_ivs: 3, probabilities: [0, 0, 25, 25, 0] },
  DenEncounter { species: types::Species::Drifblim, flawless_ivs: 3, probabilities: [0, 0, 15, 25, 0] },
  DenEncounter { species: types::Species::Gourgeist, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Gourgeist, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Gourgeist, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Gourgeist, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 20] },
  DenEncounter { species: types::Species::Palossand, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
];

#[rustfmt::skip]
const NEST_50EAF4685FA07085: DenEncounters = [
  DenEncounter { species: types::Species::Chansey, flawless_ivs: 4, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Klefki, flawless_ivs: 1, probabilities: [60, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Magnemite, flawless_ivs: 1, probabilities: [40, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Pawniard, flawless_ivs: 2, probabilities: [0, 25, 30, 0, 0] },
  DenEncounter { species: types::Species::Magnemite, flawless_ivs: 2, probabilities: [0, 20, 25, 0, 0] },
  DenEncounter { species: types::Species::Skarmory, flawless_ivs: 3, probabilities: [0, 0, 25, 25, 0] },
  DenEncounter { species: types::Species::Magneton, flawless_ivs: 3, probabilities: [0, 0, 15, 25, 0] },
  DenEncounter { species: types::Species::Magneton, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 25] },
  DenEncounter { species: types::Species::Klefki, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Bisharp, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Magnezone, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Skarmory, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
];

#[rustfmt::skip]
const NEST_F9280759D6CC62A3: DenEncounters = [
  DenEncounter { species: types::Species::Blissey, flawless_ivs: 4, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Magnemite, flawless_ivs: 1, probabilities: [60, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Skarmory, flawless_ivs: 1, probabilities: [40, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Bronzor, flawless_ivs: 2, probabilities: [0, 25, 30, 0, 0] },
  DenEncounter { species: types::Species::Meowth, flawless_ivs: 2, probabilities: [0, 20, 25, 0, 0] },
  DenEncounter { species: types::Species::Magneton, flawless_ivs: 3, probabilities: [0, 0, 25, 25, 0] },
  DenEncounter { species: types::Species::Klinklang, flawless_ivs: 3, probabilities: [0, 0, 15, 25, 0] },
  DenEncounter { species: types::Species::Skarmory, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Bronzong, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Perrserker, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Lucario, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 20] },
  DenEncounter { species: types::Species::Bisharp, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
];

#[rustfmt::skip]
const NEST_B0C9AF2202B0A19E: DenEncounters = [
  DenEncounter { species: types::Species::Chansey, flawless_ivs: 4, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::JangmoO, flawless_ivs: 1, probabilities: [60, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Horsea, flawless_ivs: 1, probabilities: [40, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Applin, flawless_ivs: 2, probabilities: [0, 25, 30, 0, 0] },
  DenEncounter { species: types::Species::Seadra, flawless_ivs: 2, probabilities: [0, 20, 25, 0, 0] },
  DenEncounter { species: types::Species::Druddigon, flawless_ivs: 3, probabilities: [0, 0, 25, 25, 0] },
  DenEncounter { species: types::Species::HakamoO, flawless_ivs: 3, probabilities: [0, 0, 15, 25, 0] },
  DenEncounter { species: types::Species::Druddigon, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 25] },
  DenEncounter { species: types::Species::Gyarados, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Flapple, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Kingdra, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::KommoO, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
];

#[rustfmt::skip]
const NEST_3D6F1FCB3898D356: DenEncounters = [
  DenEncounter { species: types::Species::Blissey, flawless_ivs: 4, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Horsea, flawless_ivs: 1, probabilities: [60, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Druddigon, flawless_ivs: 1, probabilities: [40, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Turtonator, flawless_ivs: 2, probabilities: [0, 25, 30, 0, 0] },
  DenEncounter { species: types::Species::JangmoO, flawless_ivs: 2, probabilities: [0, 20, 25, 0, 0] },
  DenEncounter { species: types::Species::Seadra, flawless_ivs: 3, probabilities: [0, 0, 25, 25, 0] },
  DenEncounter { species: types::Species::HakamoO, flawless_ivs: 3, probabilities: [0, 0, 15, 25, 0] },
  DenEncounter { species: types::Species::Turtonator, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Druddigon, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Noivern, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Kingdra, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 20] },
  DenEncounter { species: types::Species::KommoO, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
];

#[rustfmt::skip]
const NEST_4257E50E1C471596: DenEncounters = [
  DenEncounter { species: types::Species::Chansey, flawless_ivs: 4, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Poliwag, flawless_ivs: 1, probabilities: [60, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Wooper, flawless_ivs: 1, probabilities: [40, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Goldeen, flawless_ivs: 2, probabilities: [0, 25, 30, 0, 0] },
  DenEncounter { species: types::Species::Poliwhirl, flawless_ivs: 2, probabilities: [0, 20, 25, 0, 0] },
  DenEncounter { species: types::Species::Crawdaunt, flawless_ivs: 3, probabilities: [0, 0, 25, 25, 0] },
  DenEncounter { species: types::Species::Poliwhirl, flawless_ivs: 3, probabilities: [0, 0, 15, 25, 0] },
  DenEncounter { species: types::Species::Seaking, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 25] },
  DenEncounter { species: types::Species::Crawdaunt, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Quagsire, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Poliwrath, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Politoed, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
];

#[rustfmt::skip]
const NEST_FE9697F9799C65BE: DenEncounters = [
  DenEncounter { species: types::Species::Blissey, flawless_ivs: 4, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Corphish, flawless_ivs: 1, probabilities: [60, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Dewpider, flawless_ivs: 1, probabilities: [40, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Goldeen, flawless_ivs: 2, probabilities: [0, 25, 30, 0, 0] },
  DenEncounter { species: types::Species::Poliwhirl, flawless_ivs: 2, probabilities: [0, 20, 25, 0, 0] },
  DenEncounter { species: types::Species::Crawdaunt, flawless_ivs: 3, probabilities: [0, 0, 25, 25, 0] },
  DenEncounter { species: types::Species::Quagsire, flawless_ivs: 3, probabilities: [0, 0, 15, 25, 0] },
  DenEncounter { species: types::Species::Seaking, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Poliwrath, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Crawdaunt, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Araquanid, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 20] },
  DenEncounter { species: types::Species::Politoed, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
];

#[rustfmt::skip]
const NEST_4257E40E1C4713E3: DenEncounters = [
  DenEncounter { species: types::Species::Chansey, flawless_ivs: 4, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Psyduck, flawless_ivs: 1, probabilities: [60, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Chewtle, flawless_ivs: 1, probabilities: [40, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Arrokuda, flawless_ivs: 2, probabilities: [0, 25, 30, 0, 0] },
  DenEncounter { species: types::Species::Barboach, flawless_ivs: 2, probabilities: [0, 20, 25, 0, 0] },
  DenEncounter { species: types::Species::Golduck, flawless_ivs: 3, probabilities: [0, 0, 25, 25, 0] },
  DenEncounter { species: types::Species::Cramorant, flawless_ivs: 3, probabilities: [0, 0, 15, 25, 0] },
  DenEncounter { species: types::Species::Golduck, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 25] },
  DenEncounter { species: types::Species::Barraskewda, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Drednaw, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Whiscash, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Golduck, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
];

#[rustfmt::skip]
const NEST_FE9696F9799C640B: DenEncounters = [
  DenEncounter { species: types::Species::Blissey, flawless_ivs: 4, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Arrokuda, flawless_ivs: 1, probabilities: [60, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Tympole, flawless_ivs: 1, probabilities: [40, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Psyduck, flawless_ivs: 2, probabilities: [0, 25, 30, 0, 0] },
  DenEncounter { species: types::Species::Palpitoad, flawless_ivs: 2, probabilities: [0, 20, 25, 0, 0] },
  DenEncounter { species: types::Species::Golduck, flawless_ivs: 3, probabilities: [0, 0, 25, 25, 0] },
  DenEncounter { species: types::Species::Whiscash, flawless_ivs: 3, probabilities: [0, 0, 15, 25, 0] },
  DenEncounter { species: types::Species::Golduck, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Barraskewda, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Seismitoad, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Gyarados, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 20] },
  DenEncounter { species: types::Species::Basculin, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
];

#[rustfmt::skip]
const NEST_4257E30E1C471230: DenEncounters = [
  DenEncounter { species: types::Species::Chansey, flawless_ivs: 4, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Tentacool, flawless_ivs: 1, probabilities: [60, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Krabby, flawless_ivs: 1, probabilities: [40, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Tentacool, flawless_ivs: 2, probabilities: [0, 25, 30, 0, 0] },
  DenEncounter { species: types::Species::Remoraid, flawless_ivs: 2, probabilities: [0, 20, 25, 0, 0] },
  DenEncounter { species: types::Species::Tentacruel, flawless_ivs: 3, probabilities: [0, 0, 25, 25, 0] },
  DenEncounter { species: types::Species::Wishiwashi, flawless_ivs: 3, probabilities: [0, 0, 15, 25, 0] },
  DenEncounter { species: types::Species::Octillery, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 25] },
  DenEncounter { species: types::Species::Mantine, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Kingler, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Cloyster, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Tentacruel, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
];

#[rustfmt::skip]
const NEST_FE9695F9799C6258: DenEncounters = [
  DenEncounter { species: types::Species::Blissey, flawless_ivs: 4, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Shellder, flawless_ivs: 1, probabilities: [60, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Binacle, flawless_ivs: 1, probabilities: [40, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Mareanie, flawless_ivs: 2, probabilities: [0, 25, 30, 0, 0] },
  DenEncounter { species: types::Species::Remoraid, flawless_ivs: 2, probabilities: [0, 20, 25, 0, 0] },
  DenEncounter { species: types::Species::Tentacruel, flawless_ivs: 3, probabilities: [0, 0, 25, 25, 0] },
  DenEncounter { species: types::Species::Pyukumuku, flawless_ivs: 3, probabilities: [0, 0, 15, 25, 0] },
  DenEncounter { species: types::Species::Octillery, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Mantine, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Barbaracle, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Cloyster, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 20] },
  DenEncounter { species: types::Species::Toxapex, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
];

#[rustfmt::skip]
const NEST_4257EA0E1C471E15: DenEncounters = [
  DenEncounter { species: types::Species::Chansey, flawless_ivs: 4, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Chinchou, flawless_ivs: 1, probabilities: [60, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Clauncher, flawless_ivs: 1, probabilities: [40, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Clauncher, flawless_ivs: 2, probabilities: [0, 25, 30, 0, 0] },
  DenEncounter { species: types::Species::Staryu, flawless_ivs: 2, probabilities: [0, 20, 25, 0, 0] },
  DenEncounter { species: types::Species::Wailmer, flawless_ivs: 3, probabilities: [0, 0, 25, 25, 0] },
  DenEncounter { species: types::Species::Wishiwashi, flawless_ivs: 3, probabilities: [0, 0, 15, 25, 0] },
  DenEncounter { species: types::Species::Wailord, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 25] },
  DenEncounter { species: types::Species::Lanturn, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Starmie, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Clawitzer, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Sharpedo, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
];

#[rustfmt::skip]
const NEST_FE969CF9799C6E3D: DenEncounters = [
  DenEncounter { species: types::Species::Blissey, flawless_ivs: 4, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Clauncher, flawless_ivs: 1, probabilities: [60, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Staryu, flawless_ivs: 1, probabilities: [40, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Wailmer, flawless_ivs: 2, probabilities: [0, 25, 30, 0, 0] },
  DenEncounter { species: types::Species::Pelipper, flawless_ivs: 2, probabilities: [0, 20, 25, 0, 0] },
  DenEncounter { species: types::Species::Lanturn, flawless_ivs: 3, probabilities: [0, 0, 25, 25, 0] },
  DenEncounter { species: types::Species::Seadra, flawless_ivs: 3, probabilities: [0, 0, 15, 25, 0] },
  DenEncounter { species: types::Species::Clawitzer, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Lanturn, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Starmie, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Clawitzer, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 20] },
  DenEncounter { species: types::Species::Sharpedo, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
];

#[rustfmt::skip]
const NEST_EA4C3915EA6F95A0: DenEncounters = [
  DenEncounter { species: types::Species::Chansey, flawless_ivs: 4, probabilities: [0, 0, 5, 6, 7] },
  DenEncounter { species: types::Species::Combee, flawless_ivs: 1, probabilities: [60, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Combee, flawless_ivs: 1, probabilities: [40, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Combee, flawless_ivs: 2, probabilities: [0, 25, 30, 0, 0] },
  DenEncounter { species: types::Species::Combee, flawless_ivs: 2, probabilities: [0, 20, 25, 0, 0] },
  DenEncounter { species: types::Species::Combee, flawless_ivs: 3, probabilities: [0, 0, 25, 24, 0] },
  DenEncounter { species: types::Species::Combee, flawless_ivs: 3, probabilities: [0, 0, 15, 25, 0] },
  DenEncounter { species: types::Species::Vespiquen, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 23] },
  DenEncounter { species: types::Species::Vespiquen, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Vespiquen, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Vespiquen, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Vespiquen, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
];

#[rustfmt::skip]
const NEST_3EA9DF3B7B2B5990: DenEncounters = [
  DenEncounter { species: types::Species::Blissey, flawless_ivs: 4, probabilities: [0, 0, 5, 6, 7] },
  DenEncounter { species: types::Species::Combee, flawless_ivs: 1, probabilities: [60, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Combee, flawless_ivs: 1, probabilities: [40, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Combee, flawless_ivs: 2, probabilities: [0, 25, 30, 0, 0] },
  DenEncounter { species: types::Species::Combee, flawless_ivs: 2, probabilities: [0, 20, 25, 0, 0] },
  DenEncounter { species: types::Species::Vespiquen, flawless_ivs: 3, probabilities: [0, 0, 25, 24, 0] },
  DenEncounter { species: types::Species::Vespiquen, flawless_ivs: 3, probabilities: [0, 0, 15, 25, 0] },
  DenEncounter { species: types::Species::Vespiquen, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 18] },
  DenEncounter { species: types::Species::Vespiquen, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Vespiquen, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Vespiquen, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 20] },
  DenEncounter { species: types::Species::Vespiquen, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
];

#[rustfmt::skip]
const NEST_4F1E561DD73ED3D8: DenEncounters = [
  DenEncounter { species: types::Species::Blissey, flawless_ivs: 4, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Foongus, flawless_ivs: 1, probabilities: [60, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Exeggcute, flawless_ivs: 1, probabilities: [40, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Tangela, flawless_ivs: 2, probabilities: [0, 25, 30, 0, 0] },
  DenEncounter { species: types::Species::Roselia, flawless_ivs: 2, probabilities: [0, 20, 25, 0, 0] },
  DenEncounter { species: types::Species::Tangela, flawless_ivs: 3, probabilities: [0, 0, 25, 25, 0] },
  DenEncounter { species: types::Species::Roselia, flawless_ivs: 3, probabilities: [0, 0, 15, 25, 0] },
  DenEncounter { species: types::Species::Exeggutor, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 25] },
  DenEncounter { species: types::Species::Venusaur, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 25] },
  DenEncounter { species: types::Species::Tangrowth, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Roserade, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 20] },
  DenEncounter { species: types::Species::Venusaur, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 5] },
];

#[rustfmt::skip]
const NEST_4F1E591DD73ED8F1: DenEncounters = [
  DenEncounter { species: types::Species::Blissey, flawless_ivs: 4, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Magikarp, flawless_ivs: 1, probabilities: [60, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Tentacool, flawless_ivs: 1, probabilities: [40, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Staryu, flawless_ivs: 2, probabilities: [0, 25, 30, 0, 0] },
  DenEncounter { species: types::Species::Binacle, flawless_ivs: 2, probabilities: [0, 20, 25, 0, 0] },
  DenEncounter { species: types::Species::Tentacruel, flawless_ivs: 3, probabilities: [0, 0, 25, 25, 0] },
  DenEncounter { species: types::Species::Gyarados, flawless_ivs: 3, probabilities: [0, 0, 15, 25, 0] },
  DenEncounter { species: types::Species::Tentacruel, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 25] },
  DenEncounter { species: types::Species::Gyarados, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 25] },
  DenEncounter { species: types::Species::Starmie, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Barbaracle, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 20] },
  DenEncounter { species: types::Species::Blastoise, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 5] },
];

#[rustfmt::skip]
const NEST_4F1E581DD73ED73E: DenEncounters = [
  DenEncounter { species: types::Species::Blissey, flawless_ivs: 4, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Krabby, flawless_ivs: 1, probabilities: [60, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Binacle, flawless_ivs: 1, probabilities: [40, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Tentacool, flawless_ivs: 2, probabilities: [0, 25, 30, 0, 0] },
  DenEncounter { species: types::Species::Remoraid, flawless_ivs: 2, probabilities: [0, 20, 25, 0, 0] },
  DenEncounter { species: types::Species::Tentacruel, flawless_ivs: 3, probabilities: [0, 0, 25, 25, 0] },
  DenEncounter { species: types::Species::Octillery, flawless_ivs: 3, probabilities: [0, 0, 15, 25, 0] },
  DenEncounter { species: types::Species::Avalugg, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 25] },
  DenEncounter { species: types::Species::Beartic, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 25] },
  DenEncounter { species: types::Species::Kingler, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Cloyster, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Kingler, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 10] },
];

#[rustfmt::skip]
const NEST_4F1E5B1DD73EDC57: DenEncounters = [
  DenEncounter { species: types::Species::Blissey, flawless_ivs: 4, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Chewtle, flawless_ivs: 1, probabilities: [60, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Psyduck, flawless_ivs: 1, probabilities: [40, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Barboach, flawless_ivs: 2, probabilities: [0, 25, 30, 0, 0] },
  DenEncounter { species: types::Species::Basculin, flawless_ivs: 2, probabilities: [0, 20, 25, 0, 0] },
  DenEncounter { species: types::Species::Golduck, flawless_ivs: 3, probabilities: [0, 0, 25, 25, 0] },
  DenEncounter { species: types::Species::Cramorant, flawless_ivs: 3, probabilities: [0, 0, 15, 25, 0] },
  DenEncounter { species: types::Species::Golduck, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 25] },
  DenEncounter { species: types::Species::Barraskewda, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 25] },
  DenEncounter { species: types::Species::Basculin, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Whiscash, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Drednaw, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 10] },
];

#[rustfmt::skip]
const NEST_4F1E5A1DD73EDAA4: DenEncounters = [
  DenEncounter { species: types::Species::Blissey, flawless_ivs: 4, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Blipbug, flawless_ivs: 1, probabilities: [60, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Cutiefly, flawless_ivs: 1, probabilities: [40, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Joltik, flawless_ivs: 2, probabilities: [0, 25, 30, 0, 0] },
  DenEncounter { species: types::Species::Pinsir, flawless_ivs: 2, probabilities: [0, 20, 25, 0, 0] },
  DenEncounter { species: types::Species::Dottler, flawless_ivs: 3, probabilities: [0, 0, 25, 25, 0] },
  DenEncounter { species: types::Species::Ninjask, flawless_ivs: 3, probabilities: [0, 0, 15, 25, 0] },
  DenEncounter { species: types::Species::Orbeetle, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 25] },
  DenEncounter { species: types::Species::Galvantula, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 25] },
  DenEncounter { species: types::Species::Ribombee, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Ninjask, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Orbeetle, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 10] },
];

#[rustfmt::skip]
const NEST_4F1E5D1DD73EDFBD: DenEncounters = [
  DenEncounter { species: types::Species::Blissey, flawless_ivs: 4, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Silicobra, flawless_ivs: 1, probabilities: [60, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Drilbur, flawless_ivs: 1, probabilities: [40, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Silicobra, flawless_ivs: 2, probabilities: [0, 25, 30, 0, 0] },
  DenEncounter { species: types::Species::Drilbur, flawless_ivs: 2, probabilities: [0, 20, 25, 0, 0] },
  DenEncounter { species: types::Species::Sandslash, flawless_ivs: 3, probabilities: [0, 0, 25, 25, 0] },
  DenEncounter { species: types::Species::Krokorok, flawless_ivs: 3, probabilities: [0, 0, 15, 25, 0] },
  DenEncounter { species: types::Species::Sandaconda, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 25] },
  DenEncounter { species: types::Species::Krookodile, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 25] },
  DenEncounter { species: types::Species::Excadrill, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Krookodile, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Sandaconda, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 10] },
];

#[rustfmt::skip]
const NEST_4F1E5C1DD73EDE0A: DenEncounters = [
  DenEncounter { species: types::Species::Blissey, flawless_ivs: 4, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Applin, flawless_ivs: 1, probabilities: [60, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Bounsweet, flawless_ivs: 1, probabilities: [40, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Cherubi, flawless_ivs: 2, probabilities: [0, 25, 30, 0, 0] },
  DenEncounter { species: types::Species::Applin, flawless_ivs: 2, probabilities: [0, 20, 25, 0, 0] },
  DenEncounter { species: types::Species::Steenee, flawless_ivs: 3, probabilities: [0, 0, 25, 25, 0] },
  DenEncounter { species: types::Species::Flapple, flawless_ivs: 3, probabilities: [0, 0, 15, 25, 0] },
  DenEncounter { species: types::Species::Greedent, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 25] },
  DenEncounter { species: types::Species::Flapple, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 25] },
  DenEncounter { species: types::Species::Greedent, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Tsareena, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Flapple, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 10] },
];

#[rustfmt::skip]
const NEST_40BDBE4F3BCBAC86: DenEncounters = [
  DenEncounter { species: types::Species::Chansey, flawless_ivs: 4, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Ditto, flawless_ivs: 1, probabilities: [50, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Ditto, flawless_ivs: 2, probabilities: [25, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Ditto, flawless_ivs: 2, probabilities: [25, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Ditto, flawless_ivs: 3, probabilities: [0, 25, 25, 0, 0] },
  DenEncounter { species: types::Species::Ditto, flawless_ivs: 3, probabilities: [0, 25, 25, 0, 0] },
  DenEncounter { species: types::Species::Ditto, flawless_ivs: 3, probabilities: [0, 0, 25, 25, 0] },
  DenEncounter { species: types::Species::Ditto, flawless_ivs: 3, probabilities: [0, 0, 20, 25, 0] },
  DenEncounter { species: types::Species::Ditto, flawless_ivs: 4, probabilities: [0, 0, 0, 25, 25] },
  DenEncounter { species: types::Species::Ditto, flawless_ivs: 4, probabilities: [0, 0, 0, 20, 25] },
  DenEncounter { species: types::Species::Ditto, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 25] },
  DenEncounter { species: types::Species::Ditto, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 20] },
];

#[rustfmt::skip]
const NEST_9FDF11A0CDE96B2E: DenEncounters = [
  DenEncounter { species: types::Species::Blissey, flawless_ivs: 4, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Ditto, flawless_ivs: 1, probabilities: [50, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Ditto, flawless_ivs: 2, probabilities: [25, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Ditto, flawless_ivs: 2, probabilities: [25, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Ditto, flawless_ivs: 3, probabilities: [0, 25, 25, 0, 0] },
  DenEncounter { species: types::Species::Ditto, flawless_ivs: 3, probabilities: [0, 25, 25, 0, 0] },
  DenEncounter { species: types::Species::Ditto, flawless_ivs: 3, probabilities: [0, 0, 25, 25, 0] },
  DenEncounter { species: types::Species::Ditto, flawless_ivs: 3, probabilities: [0, 0, 20, 25, 0] },
  DenEncounter { species: types::Species::Ditto, flawless_ivs: 4, probabilities: [0, 0, 0, 25, 25] },
  DenEncounter { species: types::Species::Ditto, flawless_ivs: 4, probabilities: [0, 0, 0, 20, 25] },
  DenEncounter { species: types::Species::Ditto, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 25] },
  DenEncounter { species: types::Species::Ditto, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 20] },
];

#[rustfmt::skip]
const NEST_DB8629CBA3383296: DenEncounters = [
  DenEncounter { species: types::Species::Chansey, flawless_ivs: 4, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Foongus, flawless_ivs: 1, probabilities: [60, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Exeggcute, flawless_ivs: 1, probabilities: [40, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Fomantis, flawless_ivs: 2, probabilities: [0, 25, 30, 0, 0] },
  DenEncounter { species: types::Species::Tangela, flawless_ivs: 2, probabilities: [0, 20, 25, 0, 0] },
  DenEncounter { species: types::Species::Lurantis, flawless_ivs: 3, probabilities: [0, 0, 25, 25, 0] },
  DenEncounter { species: types::Species::Exeggcute, flawless_ivs: 3, probabilities: [0, 0, 15, 25, 0] },
  DenEncounter { species: types::Species::Exeggutor, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 25] },
  DenEncounter { species: types::Species::Amoonguss, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 25] },
  DenEncounter { species: types::Species::Lurantis, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Tangrowth, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Venusaur, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 10] },
];

#[rustfmt::skip]
const NEST_6B37A94863BF68C0: DenEncounters = [
  DenEncounter { species: types::Species::Chansey, flawless_ivs: 4, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Magikarp, flawless_ivs: 1, probabilities: [60, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Tentacool, flawless_ivs: 1, probabilities: [40, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Staryu, flawless_ivs: 2, probabilities: [0, 25, 30, 0, 0] },
  DenEncounter { species: types::Species::Shellder, flawless_ivs: 2, probabilities: [0, 20, 25, 0, 0] },
  DenEncounter { species: types::Species::Tentacruel, flawless_ivs: 3, probabilities: [0, 0, 25, 25, 0] },
  DenEncounter { species: types::Species::Gyarados, flawless_ivs: 3, probabilities: [0, 0, 15, 25, 0] },
  DenEncounter { species: types::Species::Tentacruel, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 25] },
  DenEncounter { species: types::Species::Gyarados, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 25] },
  DenEncounter { species: types::Species::Starmie, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Cloyster, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Blastoise, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 10] },
];

#[rustfmt::skip]
const NEST_5584521F1E549486: DenEncounters = [
  DenEncounter { species: types::Species::Chansey, flawless_ivs: 4, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Rockruff, flawless_ivs: 1, probabilities: [50, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Rockruff, flawless_ivs: 1, probabilities: [50, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Rockruff, flawless_ivs: 2, probabilities: [0, 20, 35, 0, 0] },
  DenEncounter { species: types::Species::Rockruff, flawless_ivs: 2, probabilities: [0, 20, 35, 0, 0] },
  DenEncounter { species: types::Species::Rockruff, flawless_ivs: 3, probabilities: [0, 0, 20, 40, 0] },
  DenEncounter { species: types::Species::Rockruff, flawless_ivs: 3, probabilities: [0, 0, 5, 5, 0] },
  DenEncounter { species: types::Species::Lycanroc, flawless_ivs: 4, probabilities: [0, 0, 0, 20, 25] },
  DenEncounter { species: types::Species::Lycanroc, flawless_ivs: 4, probabilities: [0, 0, 0, 20, 25] },
  DenEncounter { species: types::Species::Lycanroc, flawless_ivs: 4, probabilities: [0, 0, 0, 10, 20] },
  DenEncounter { species: types::Species::Lycanroc, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 20] },
  DenEncounter { species: types::Species::Lycanroc, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 5] },
];

#[rustfmt::skip]
const NEST_55846E1F1E54C41A: DenEncounters = [
  DenEncounter { species: types::Species::Blissey, flawless_ivs: 4, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Rockruff, flawless_ivs: 1, probabilities: [50, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Rockruff, flawless_ivs: 1, probabilities: [50, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Rockruff, flawless_ivs: 2, probabilities: [0, 20, 30, 0, 0] },
  DenEncounter { species: types::Species::Rockruff, flawless_ivs: 2, probabilities: [0, 20, 30, 0, 0] },
  DenEncounter { species: types::Species::Rockruff, flawless_ivs: 3, probabilities: [0, 0, 20, 30, 0] },
  DenEncounter { species: types::Species::Rockruff, flawless_ivs: 3, probabilities: [0, 0, 15, 15, 0] },
  DenEncounter { species: types::Species::Lycanroc, flawless_ivs: 4, probabilities: [0, 0, 0, 30, 0] },
  DenEncounter { species: types::Species::Lycanroc, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 0] },
  DenEncounter { species: types::Species::Lycanroc, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 40] },
  DenEncounter { species: types::Species::Lycanroc, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 35] },
  DenEncounter { species: types::Species::Lycanroc, flawless_ivs: 4, probabilities: [0, 0, 0, 5, 20] },
];

#[rustfmt::skip]
const NEST_2640FA844B19C3CF: DenEncounters = [
  DenEncounter { species: types::Species::Audino, flawless_ivs: 4, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Swablu, flawless_ivs: 1, probabilities: [60, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Wooloo, flawless_ivs: 1, probabilities: [40, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Swablu, flawless_ivs: 2, probabilities: [0, 25, 30, 0, 0] },
  DenEncounter { species: types::Species::Munchlax, flawless_ivs: 2, probabilities: [0, 20, 25, 0, 0] },
  DenEncounter { species: types::Species::Greedent, flawless_ivs: 3, probabilities: [0, 0, 25, 25, 0] },
  DenEncounter { species: types::Species::Dubwool, flawless_ivs: 3, probabilities: [0, 0, 15, 25, 0] },
  DenEncounter { species: types::Species::Altaria, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 25] },
  DenEncounter { species: types::Species::Altaria, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Dubwool, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Snorlax, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Snorlax, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
];

#[rustfmt::skip]
const NEST_422F95FB66A95706: DenEncounters = [
  DenEncounter { species: types::Species::Delibird, flawless_ivs: 5, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Swablu, flawless_ivs: 2, probabilities: [60, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Skwovet, flawless_ivs: 2, probabilities: [40, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Swablu, flawless_ivs: 3, probabilities: [0, 25, 30, 0, 0] },
  DenEncounter { species: types::Species::Greedent, flawless_ivs: 3, probabilities: [0, 20, 25, 0, 0] },
  DenEncounter { species: types::Species::Greedent, flawless_ivs: 4, probabilities: [0, 0, 25, 25, 0] },
  DenEncounter { species: types::Species::Dubwool, flawless_ivs: 4, probabilities: [0, 0, 15, 25, 0] },
  DenEncounter { species: types::Species::Altaria, flawless_ivs: 5, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Altaria, flawless_ivs: 5, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Dubwool, flawless_ivs: 5, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Snorlax, flawless_ivs: 5, probabilities: [0, 0, 0, 0, 20] },
  DenEncounter { species: types::Species::Snorlax, flawless_ivs: 5, probabilities: [0, 0, 0, 0, 15] },
];

#[rustfmt::skip]
const NEST_3A41C5C485D3EDEE: DenEncounters = [
  DenEncounter { species: types::Species::Audino, flawless_ivs: 4, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Magby, flawless_ivs: 1, probabilities: [60, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Sizzlipede, flawless_ivs: 1, probabilities: [40, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Magby, flawless_ivs: 2, probabilities: [0, 25, 30, 0, 0] },
  DenEncounter { species: types::Species::Heatmor, flawless_ivs: 2, probabilities: [0, 20, 25, 0, 0] },
  DenEncounter { species: types::Species::Lampent, flawless_ivs: 3, probabilities: [0, 0, 25, 25, 0] },
  DenEncounter { species: types::Species::Heatmor, flawless_ivs: 3, probabilities: [0, 0, 15, 25, 0] },
  DenEncounter { species: types::Species::Magmar, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 25] },
  DenEncounter { species: types::Species::Centiskorch, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Chandelure, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Magmar, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Magmortar, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
];

#[rustfmt::skip]
const NEST_6C364ECC3616AF63: DenEncounters = [
  DenEncounter { species: types::Species::Delibird, flawless_ivs: 5, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Magby, flawless_ivs: 2, probabilities: [60, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Magby, flawless_ivs: 2, probabilities: [40, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Magmar, flawless_ivs: 3, probabilities: [0, 25, 30, 0, 0] },
  DenEncounter { species: types::Species::Heatmor, flawless_ivs: 3, probabilities: [0, 20, 25, 0, 0] },
  DenEncounter { species: types::Species::Magmar, flawless_ivs: 4, probabilities: [0, 0, 25, 25, 0] },
  DenEncounter { species: types::Species::Centiskorch, flawless_ivs: 4, probabilities: [0, 0, 15, 25, 0] },
  DenEncounter { species: types::Species::Chandelure, flawless_ivs: 5, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Ninetales, flawless_ivs: 5, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Magmortar, flawless_ivs: 5, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Magmortar, flawless_ivs: 5, probabilities: [0, 0, 0, 0, 20] },
  DenEncounter { species: types::Species::Centiskorch, flawless_ivs: 5, probabilities: [0, 0, 0, 0, 15] },
];

#[rustfmt::skip]
const NEST_F6389AD0BC9AAEB: DenEncounters = [
  DenEncounter { species: types::Species::Audino, flawless_ivs: 4, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Omanyte, flawless_ivs: 1, probabilities: [60, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Feebas, flawless_ivs: 1, probabilities: [40, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Omanyte, flawless_ivs: 2, probabilities: [0, 25, 30, 0, 0] },
  DenEncounter { species: types::Species::Feebas, flawless_ivs: 2, probabilities: [0, 20, 25, 0, 0] },
  DenEncounter { species: types::Species::Whiscash, flawless_ivs: 3, probabilities: [0, 0, 25, 25, 0] },
  DenEncounter { species: types::Species::Basculin, flawless_ivs: 3, probabilities: [0, 0, 15, 25, 0] },
  DenEncounter { species: types::Species::Omastar, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 25] },
  DenEncounter { species: types::Species::Basculin, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Gyarados, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Milotic, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Relicanth, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
];

#[rustfmt::skip]
const NEST_277EFFBE0B116E4A: DenEncounters = [
  DenEncounter { species: types::Species::Delibird, flawless_ivs: 5, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Feebas, flawless_ivs: 2, probabilities: [60, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Omanyte, flawless_ivs: 2, probabilities: [40, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Feebas, flawless_ivs: 3, probabilities: [0, 25, 30, 0, 0] },
  DenEncounter { species: types::Species::Relicanth, flawless_ivs: 3, probabilities: [0, 20, 25, 0, 0] },
  DenEncounter { species: types::Species::Basculin, flawless_ivs: 4, probabilities: [0, 0, 25, 25, 0] },
  DenEncounter { species: types::Species::Kingler, flawless_ivs: 4, probabilities: [0, 0, 15, 25, 0] },
  DenEncounter { species: types::Species::Relicanth, flawless_ivs: 5, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Omastar, flawless_ivs: 5, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Milotic, flawless_ivs: 5, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Gyarados, flawless_ivs: 5, probabilities: [0, 0, 0, 0, 20] },
  DenEncounter { species: types::Species::Kingler, flawless_ivs: 5, probabilities: [0, 0, 0, 0, 15] },
];

#[rustfmt::skip]
const NEST_E234E939402A736B: DenEncounters = [
  DenEncounter { species: types::Species::Audino, flawless_ivs: 4, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Elekid, flawless_ivs: 1, probabilities: [60, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Joltik, flawless_ivs: 1, probabilities: [40, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Elekid, flawless_ivs: 2, probabilities: [0, 25, 30, 0, 0] },
  DenEncounter { species: types::Species::Pincurchin, flawless_ivs: 2, probabilities: [0, 20, 25, 0, 0] },
  DenEncounter { species: types::Species::Electabuzz, flawless_ivs: 3, probabilities: [0, 0, 25, 25, 0] },
  DenEncounter { species: types::Species::Mimikyu, flawless_ivs: 3, probabilities: [0, 0, 15, 25, 0] },
  DenEncounter { species: types::Species::Galvantula, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 25] },
  DenEncounter { species: types::Species::Pincurchin, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Boltund, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Electabuzz, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Electivire, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
];

#[rustfmt::skip]
const NEST_3B3C0865D15B0ACA: DenEncounters = [
  DenEncounter { species: types::Species::Delibird, flawless_ivs: 5, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Elekid, flawless_ivs: 2, probabilities: [60, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Elekid, flawless_ivs: 2, probabilities: [40, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Dedenne, flawless_ivs: 3, probabilities: [0, 25, 30, 0, 0] },
  DenEncounter { species: types::Species::Galvantula, flawless_ivs: 3, probabilities: [0, 20, 25, 0, 0] },
  DenEncounter { species: types::Species::Electabuzz, flawless_ivs: 4, probabilities: [0, 0, 25, 25, 0] },
  DenEncounter { species: types::Species::Boltund, flawless_ivs: 4, probabilities: [0, 0, 15, 25, 0] },
  DenEncounter { species: types::Species::Toxtricity, flawless_ivs: 5, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Pincurchin, flawless_ivs: 5, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Electivire, flawless_ivs: 5, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Electivire, flawless_ivs: 5, probabilities: [0, 0, 0, 0, 20] },
  DenEncounter { species: types::Species::Toxtricity, flawless_ivs: 5, probabilities: [0, 0, 0, 0, 15] },
];

#[rustfmt::skip]
const NEST_779E9EB99C1292C: DenEncounters = [
  DenEncounter { species: types::Species::Audino, flawless_ivs: 4, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Gossifleur, flawless_ivs: 1, probabilities: [60, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Anorith, flawless_ivs: 1, probabilities: [40, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Anorith, flawless_ivs: 2, probabilities: [0, 25, 30, 0, 0] },
  DenEncounter { species: types::Species::Lileep, flawless_ivs: 2, probabilities: [0, 20, 25, 0, 0] },
  DenEncounter { species: types::Species::Anorith, flawless_ivs: 3, probabilities: [0, 0, 25, 25, 0] },
  DenEncounter { species: types::Species::Eldegoss, flawless_ivs: 3, probabilities: [0, 0, 15, 25, 0] },
  DenEncounter { species: types::Species::Armaldo, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 25] },
  DenEncounter { species: types::Species::Araquanid, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Eldegoss, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Ferrothorn, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Cradily, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
];

#[rustfmt::skip]
const NEST_93A637943A964E41: DenEncounters = [
  DenEncounter { species: types::Species::Delibird, flawless_ivs: 5, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Anorith, flawless_ivs: 2, probabilities: [60, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Lileep, flawless_ivs: 2, probabilities: [40, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Anorith, flawless_ivs: 3, probabilities: [0, 25, 30, 0, 0] },
  DenEncounter { species: types::Species::Lileep, flawless_ivs: 3, probabilities: [0, 20, 25, 0, 0] },
  DenEncounter { species: types::Species::Araquanid, flawless_ivs: 4, probabilities: [0, 0, 25, 25, 0] },
  DenEncounter { species: types::Species::Butterfree, flawless_ivs: 4, probabilities: [0, 0, 15, 25, 0] },
  DenEncounter { species: types::Species::Armaldo, flawless_ivs: 5, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Cradily, flawless_ivs: 5, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Eldegoss, flawless_ivs: 5, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Armaldo, flawless_ivs: 5, probabilities: [0, 0, 0, 0, 20] },
  DenEncounter { species: types::Species::Butterfree, flawless_ivs: 5, probabilities: [0, 0, 0, 0, 15] },
];

#[rustfmt::skip]
const NEST_685DB02AAEDBCF61: DenEncounters = [
  DenEncounter { species: types::Species::Audino, flawless_ivs: 4, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Smoochum, flawless_ivs: 1, probabilities: [60, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Darumaka, flawless_ivs: 1, probabilities: [40, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Smoochum, flawless_ivs: 2, probabilities: [0, 25, 30, 0, 0] },
  DenEncounter { species: types::Species::Amaura, flawless_ivs: 2, probabilities: [0, 20, 25, 0, 0] },
  DenEncounter { species: types::Species::Piloswine, flawless_ivs: 3, probabilities: [0, 0, 25, 25, 0] },
  DenEncounter { species: types::Species::Abomasnow, flawless_ivs: 3, probabilities: [0, 0, 15, 25, 0] },
  DenEncounter { species: types::Species::Jynx, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 25] },
  DenEncounter { species: types::Species::Frosmoth, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Darmanitan, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Aurorus, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Glalie, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
];

#[rustfmt::skip]
const NEST_2CD8CF9A88739F98: DenEncounters = [
  DenEncounter { species: types::Species::Delibird, flawless_ivs: 5, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Snorunt, flawless_ivs: 2, probabilities: [60, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Darumaka, flawless_ivs: 2, probabilities: [40, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Smoochum, flawless_ivs: 3, probabilities: [0, 25, 30, 0, 0] },
  DenEncounter { species: types::Species::Amaura, flawless_ivs: 3, probabilities: [0, 20, 25, 0, 0] },
  DenEncounter { species: types::Species::Glalie, flawless_ivs: 4, probabilities: [0, 0, 25, 25, 0] },
  DenEncounter { species: types::Species::Abomasnow, flawless_ivs: 4, probabilities: [0, 0, 15, 25, 0] },
  DenEncounter { species: types::Species::Jynx, flawless_ivs: 5, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Frosmoth, flawless_ivs: 5, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Darmanitan, flawless_ivs: 5, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Aurorus, flawless_ivs: 5, probabilities: [0, 0, 0, 0, 20] },
  DenEncounter { species: types::Species::Mamoswine, flawless_ivs: 5, probabilities: [0, 0, 0, 0, 15] },
];

#[rustfmt::skip]
const NEST_685DAD2AAEDBCA48: DenEncounters = [
  DenEncounter { species: types::Species::Audino, flawless_ivs: 4, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Cubchoo, flawless_ivs: 1, probabilities: [60, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Spheal, flawless_ivs: 1, probabilities: [40, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Spheal, flawless_ivs: 2, probabilities: [0, 25, 30, 0, 0] },
  DenEncounter { species: types::Species::Bergmite, flawless_ivs: 2, probabilities: [0, 20, 25, 0, 0] },
  DenEncounter { species: types::Species::Sealeo, flawless_ivs: 3, probabilities: [0, 0, 25, 25, 0] },
  DenEncounter { species: types::Species::Cryogonal, flawless_ivs: 3, probabilities: [0, 0, 15, 25, 0] },
  DenEncounter { species: types::Species::Vanilluxe, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 25] },
  DenEncounter { species: types::Species::Beartic, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Walrein, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Avalugg, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Lapras, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
];

#[rustfmt::skip]
const NEST_12AD4E9A799417A5: DenEncounters = [
  DenEncounter { species: types::Species::Delibird, flawless_ivs: 5, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Lapras, flawless_ivs: 2, probabilities: [60, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Spheal, flawless_ivs: 2, probabilities: [40, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Sealeo, flawless_ivs: 3, probabilities: [0, 25, 30, 0, 0] },
  DenEncounter { species: types::Species::Sealeo, flawless_ivs: 3, probabilities: [0, 20, 25, 0, 0] },
  DenEncounter { species: types::Species::Avalugg, flawless_ivs: 4, probabilities: [0, 0, 25, 25, 0] },
  DenEncounter { species: types::Species::Cryogonal, flawless_ivs: 4, probabilities: [0, 0, 15, 25, 0] },
  DenEncounter { species: types::Species::Walrein, flawless_ivs: 5, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Lapras, flawless_ivs: 5, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Vanilluxe, flawless_ivs: 5, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Walrein, flawless_ivs: 5, probabilities: [0, 0, 0, 0, 20] },
  DenEncounter { species: types::Species::Lapras, flawless_ivs: 5, probabilities: [0, 0, 0, 0, 15] },
];

#[rustfmt::skip]
const NEST_75319113C8C3B924: DenEncounters = [
  DenEncounter { species: types::Species::Audino, flawless_ivs: 4, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Timburr, flawless_ivs: 1, probabilities: [60, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Golett, flawless_ivs: 1, probabilities: [40, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Golett, flawless_ivs: 2, probabilities: [0, 25, 30, 0, 0] },
  DenEncounter { species: types::Species::Carkol, flawless_ivs: 2, probabilities: [0, 20, 25, 0, 0] },
  DenEncounter { species: types::Species::Gurdurr, flawless_ivs: 3, probabilities: [0, 0, 25, 25, 0] },
  DenEncounter { species: types::Species::Golurk, flawless_ivs: 3, probabilities: [0, 0, 15, 25, 0] },
  DenEncounter { species: types::Species::Conkeldurr, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 25] },
  DenEncounter { species: types::Species::Golurk, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Coalossal, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Golurk, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Conkeldurr, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
];

#[rustfmt::skip]
const NEST_314ACB827C75109: DenEncounters = [
  DenEncounter { species: types::Species::Delibird, flawless_ivs: 5, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Falinks, flawless_ivs: 2, probabilities: [60, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Tyrogue, flawless_ivs: 2, probabilities: [40, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Gurdurr, flawless_ivs: 3, probabilities: [0, 25, 30, 0, 0] },
  DenEncounter { species: types::Species::FarfetchD, flawless_ivs: 3, probabilities: [0, 20, 25, 0, 0] },
  DenEncounter { species: types::Species::Falinks, flawless_ivs: 4, probabilities: [0, 0, 25, 25, 0] },
  DenEncounter { species: types::Species::Golurk, flawless_ivs: 4, probabilities: [0, 0, 15, 25, 0] },
  DenEncounter { species: types::Species::SirfetchD, flawless_ivs: 5, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Conkeldurr, flawless_ivs: 5, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Hitmonlee, flawless_ivs: 5, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Hitmontop, flawless_ivs: 5, probabilities: [0, 0, 0, 0, 20] },
  DenEncounter { species: types::Species::Machamp, flawless_ivs: 5, probabilities: [0, 0, 0, 0, 15] },
];

#[rustfmt::skip]
const NEST_52A7DFE87897D15D: DenEncounters = [
  DenEncounter { species: types::Species::Audino, flawless_ivs: 4, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::NidoranF, flawless_ivs: 1, probabilities: [60, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Zubat, flawless_ivs: 1, probabilities: [40, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::NidoranF, flawless_ivs: 2, probabilities: [0, 25, 30, 0, 0] },
  DenEncounter { species: types::Species::NidoranM, flawless_ivs: 2, probabilities: [0, 20, 25, 0, 0] },
  DenEncounter { species: types::Species::Nidorina, flawless_ivs: 3, probabilities: [0, 0, 25, 25, 0] },
  DenEncounter { species: types::Species::Nidorino, flawless_ivs: 3, probabilities: [0, 0, 15, 25, 0] },
  DenEncounter { species: types::Species::Nidoqueen, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 25] },
  DenEncounter { species: types::Species::Golbat, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Golbat, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Nidoqueen, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Nidoking, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
];

#[rustfmt::skip]
const NEST_C88B8A5990A8EA5C: DenEncounters = [
  DenEncounter { species: types::Species::Delibird, flawless_ivs: 5, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Zubat, flawless_ivs: 2, probabilities: [60, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Trubbish, flawless_ivs: 2, probabilities: [40, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Nidorina, flawless_ivs: 3, probabilities: [0, 25, 30, 0, 0] },
  DenEncounter { species: types::Species::Slowpoke, flawless_ivs: 3, probabilities: [0, 20, 25, 0, 0] },
  DenEncounter { species: types::Species::Golbat, flawless_ivs: 4, probabilities: [0, 0, 25, 25, 0] },
  DenEncounter { species: types::Species::Garbodor, flawless_ivs: 4, probabilities: [0, 0, 15, 25, 0] },
  DenEncounter { species: types::Species::Nidoqueen, flawless_ivs: 5, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Nidoqueen, flawless_ivs: 5, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Nidoking, flawless_ivs: 5, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Crobat, flawless_ivs: 5, probabilities: [0, 0, 0, 0, 20] },
  DenEncounter { species: types::Species::Garbodor, flawless_ivs: 5, probabilities: [0, 0, 0, 0, 15] },
];

#[rustfmt::skip]
const NEST_42B21EFC37C7B974: DenEncounters = [
  DenEncounter { species: types::Species::Audino, flawless_ivs: 4, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Zubat, flawless_ivs: 1, probabilities: [60, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Noibat, flawless_ivs: 1, probabilities: [40, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Swablu, flawless_ivs: 2, probabilities: [0, 25, 30, 0, 0] },
  DenEncounter { species: types::Species::Golbat, flawless_ivs: 2, probabilities: [0, 20, 25, 0, 0] },
  DenEncounter { species: types::Species::Golbat, flawless_ivs: 3, probabilities: [0, 0, 25, 25, 0] },
  DenEncounter { species: types::Species::Corvisquire, flawless_ivs: 3, probabilities: [0, 0, 15, 25, 0] },
  DenEncounter { species: types::Species::Golbat, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 25] },
  DenEncounter { species: types::Species::Altaria, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Noivern, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Corviknight, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Crobat, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
];

#[rustfmt::skip]
const NEST_9D415F6A7A841DD9: DenEncounters = [
  DenEncounter { species: types::Species::Delibird, flawless_ivs: 5, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Zubat, flawless_ivs: 2, probabilities: [60, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Woobat, flawless_ivs: 2, probabilities: [40, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Corvisquire, flawless_ivs: 3, probabilities: [0, 25, 30, 0, 0] },
  DenEncounter { species: types::Species::Golbat, flawless_ivs: 3, probabilities: [0, 20, 25, 0, 0] },
  DenEncounter { species: types::Species::Swoobat, flawless_ivs: 4, probabilities: [0, 0, 25, 25, 0] },
  DenEncounter { species: types::Species::Corviknight, flawless_ivs: 4, probabilities: [0, 0, 15, 25, 0] },
  DenEncounter { species: types::Species::Aerodactyl, flawless_ivs: 5, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Altaria, flawless_ivs: 5, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Crobat, flawless_ivs: 5, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Noivern, flawless_ivs: 5, probabilities: [0, 0, 0, 0, 20] },
  DenEncounter { species: types::Species::Corviknight, flawless_ivs: 5, probabilities: [0, 0, 0, 0, 15] },
];

#[rustfmt::skip]
const NEST_17D327792698D15F: DenEncounters = [
  DenEncounter { species: types::Species::Audino, flawless_ivs: 4, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::MimeJr, flawless_ivs: 1, probabilities: [60, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Baltoy, flawless_ivs: 1, probabilities: [40, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Bronzor, flawless_ivs: 2, probabilities: [0, 25, 30, 0, 0] },
  DenEncounter { species: types::Species::MrMime, flawless_ivs: 2, probabilities: [0, 20, 25, 0, 0] },
  DenEncounter { species: types::Species::Gothorita, flawless_ivs: 3, probabilities: [0, 0, 25, 25, 0] },
  DenEncounter { species: types::Species::Claydol, flawless_ivs: 3, probabilities: [0, 0, 15, 25, 0] },
  DenEncounter { species: types::Species::Indeedee, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 25] },
  DenEncounter { species: types::Species::Gothitelle, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Claydol, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::MrRime, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Bronzong, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
];

#[rustfmt::skip]
const NEST_B20A5ED251CD0456: DenEncounters = [
  DenEncounter { species: types::Species::Delibird, flawless_ivs: 5, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Indeedee, flawless_ivs: 2, probabilities: [60, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Gothita, flawless_ivs: 2, probabilities: [40, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::MrMime, flawless_ivs: 3, probabilities: [0, 25, 30, 0, 0] },
  DenEncounter { species: types::Species::Slowpoke, flawless_ivs: 3, probabilities: [0, 20, 25, 0, 0] },
  DenEncounter { species: types::Species::Metang, flawless_ivs: 4, probabilities: [0, 0, 25, 25, 0] },
  DenEncounter { species: types::Species::Indeedee, flawless_ivs: 4, probabilities: [0, 0, 15, 25, 0] },
  DenEncounter { species: types::Species::Indeedee, flawless_ivs: 5, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::MrRime, flawless_ivs: 5, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Gothitelle, flawless_ivs: 5, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Gothitelle, flawless_ivs: 5, probabilities: [0, 0, 0, 0, 20] },
  DenEncounter { species: types::Species::Metagross, flawless_ivs: 5, probabilities: [0, 0, 0, 0, 15] },
];

#[rustfmt::skip]
const NEST_55E4467F01EC60BB: DenEncounters = [
  DenEncounter { species: types::Species::Audino, flawless_ivs: 4, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Stonjourner, flawless_ivs: 1, probabilities: [60, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Aron, flawless_ivs: 1, probabilities: [40, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Aron, flawless_ivs: 2, probabilities: [0, 25, 30, 0, 0] },
  DenEncounter { species: types::Species::Stonjourner, flawless_ivs: 2, probabilities: [0, 20, 25, 0, 0] },
  DenEncounter { species: types::Species::Stonjourner, flawless_ivs: 3, probabilities: [0, 0, 25, 25, 0] },
  DenEncounter { species: types::Species::Lairon, flawless_ivs: 3, probabilities: [0, 0, 15, 25, 0] },
  DenEncounter { species: types::Species::Mawile, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 25] },
  DenEncounter { species: types::Species::Lairon, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Carbink, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Aggron, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Coalossal, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
];

#[rustfmt::skip]
const NEST_A5696E4AA8D625A: DenEncounters = [
  DenEncounter { species: types::Species::Delibird, flawless_ivs: 5, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Mawile, flawless_ivs: 2, probabilities: [60, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Aron, flawless_ivs: 2, probabilities: [40, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Lairon, flawless_ivs: 3, probabilities: [0, 25, 30, 0, 0] },
  DenEncounter { species: types::Species::Lairon, flawless_ivs: 3, probabilities: [0, 20, 25, 0, 0] },
  DenEncounter { species: types::Species::Shuckle, flawless_ivs: 4, probabilities: [0, 0, 25, 25, 0] },
  DenEncounter { species: types::Species::Mawile, flawless_ivs: 4, probabilities: [0, 0, 15, 25, 0] },
  DenEncounter { species: types::Species::Mawile, flawless_ivs: 5, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Coalossal, flawless_ivs: 5, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Aggron, flawless_ivs: 5, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Aggron, flawless_ivs: 5, probabilities: [0, 0, 0, 0, 20] },
  DenEncounter { species: types::Species::Coalossal, flawless_ivs: 5, probabilities: [0, 0, 0, 0, 15] },
];

#[rustfmt::skip]
const NEST_47A5D8B98DD573AB: DenEncounters = [
  DenEncounter { species: types::Species::Audino, flawless_ivs: 4, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Dreepy, flawless_ivs: 1, probabilities: [60, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Phantump, flawless_ivs: 1, probabilities: [40, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Mimikyu, flawless_ivs: 2, probabilities: [0, 25, 30, 0, 0] },
  DenEncounter { species: types::Species::Snorunt, flawless_ivs: 2, probabilities: [0, 20, 25, 0, 0] },
  DenEncounter { species: types::Species::Drakloak, flawless_ivs: 3, probabilities: [0, 0, 25, 25, 0] },
  DenEncounter { species: types::Species::Mimikyu, flawless_ivs: 3, probabilities: [0, 0, 15, 25, 0] },
  DenEncounter { species: types::Species::Mawile, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 25] },
  DenEncounter { species: types::Species::Glalie, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Froslass, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Trevenant, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Mimikyu, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
];

#[rustfmt::skip]
const NEST_A23EC426E4E9430A: DenEncounters = [
  DenEncounter { species: types::Species::Delibird, flawless_ivs: 5, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Dreepy, flawless_ivs: 2, probabilities: [60, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Dreepy, flawless_ivs: 2, probabilities: [40, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Dreepy, flawless_ivs: 3, probabilities: [0, 25, 30, 0, 0] },
  DenEncounter { species: types::Species::Haunter, flawless_ivs: 3, probabilities: [0, 20, 25, 0, 0] },
  DenEncounter { species: types::Species::Mawile, flawless_ivs: 4, probabilities: [0, 0, 25, 25, 0] },
  DenEncounter { species: types::Species::Trevenant, flawless_ivs: 4, probabilities: [0, 0, 15, 25, 0] },
  DenEncounter { species: types::Species::Trevenant, flawless_ivs: 5, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Mawile, flawless_ivs: 5, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Dragapult, flawless_ivs: 5, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Dragapult, flawless_ivs: 5, probabilities: [0, 0, 0, 0, 20] },
  DenEncounter { species: types::Species::Gengar, flawless_ivs: 5, probabilities: [0, 0, 0, 0, 15] },
];

#[rustfmt::skip]
const NEST_3D2F6B02FC6DD797: DenEncounters = [
  DenEncounter { species: types::Species::Audino, flawless_ivs: 4, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Druddigon, flawless_ivs: 1, probabilities: [60, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Bagon, flawless_ivs: 1, probabilities: [40, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Bagon, flawless_ivs: 2, probabilities: [0, 25, 30, 0, 0] },
  DenEncounter { species: types::Species::Tyrunt, flawless_ivs: 2, probabilities: [0, 20, 25, 0, 0] },
  DenEncounter { species: types::Species::Shelgon, flawless_ivs: 3, probabilities: [0, 0, 25, 25, 0] },
  DenEncounter { species: types::Species::Dratini, flawless_ivs: 3, probabilities: [0, 0, 15, 25, 0] },
  DenEncounter { species: types::Species::Shelgon, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 25] },
  DenEncounter { species: types::Species::Druddigon, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Tyrantrum, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Salamence, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Salamence, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
];

#[rustfmt::skip]
const NEST_F9D3242B837D627E: DenEncounters = [
  DenEncounter { species: types::Species::Delibird, flawless_ivs: 5, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Duraludon, flawless_ivs: 2, probabilities: [60, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Bagon, flawless_ivs: 2, probabilities: [40, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Tyrunt, flawless_ivs: 3, probabilities: [0, 25, 30, 0, 0] },
  DenEncounter { species: types::Species::Turtonator, flawless_ivs: 3, probabilities: [0, 20, 25, 0, 0] },
  DenEncounter { species: types::Species::Shelgon, flawless_ivs: 4, probabilities: [0, 0, 25, 25, 0] },
  DenEncounter { species: types::Species::Duraludon, flawless_ivs: 4, probabilities: [0, 0, 15, 25, 0] },
  DenEncounter { species: types::Species::Dragonite, flawless_ivs: 5, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Tyrantrum, flawless_ivs: 5, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Salamence, flawless_ivs: 5, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Salamence, flawless_ivs: 5, probabilities: [0, 0, 0, 0, 20] },
  DenEncounter { species: types::Species::Duraludon, flawless_ivs: 5, probabilities: [0, 0, 0, 0, 15] },
];

#[rustfmt::skip]
const NEST_9AB5727F28C3D593: DenEncounters = [
  DenEncounter { species: types::Species::Audino, flawless_ivs: 4, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Sneasel, flawless_ivs: 1, probabilities: [60, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Impidimp, flawless_ivs: 1, probabilities: [40, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Impidimp, flawless_ivs: 2, probabilities: [0, 25, 30, 0, 0] },
  DenEncounter { species: types::Species::Morgrem, flawless_ivs: 2, probabilities: [0, 20, 25, 0, 0] },
  DenEncounter { species: types::Species::Sneasel, flawless_ivs: 3, probabilities: [0, 0, 25, 25, 0] },
  DenEncounter { species: types::Species::Linoone, flawless_ivs: 3, probabilities: [0, 0, 15, 25, 0] },
  DenEncounter { species: types::Species::Grimmsnarl, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 25] },
  DenEncounter { species: types::Species::Absol, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Obstagoon, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Absol, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Weavile, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
];

#[rustfmt::skip]
const NEST_1928030AD989AD02: DenEncounters = [
  DenEncounter { species: types::Species::Delibird, flawless_ivs: 5, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Impidimp, flawless_ivs: 2, probabilities: [60, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Absol, flawless_ivs: 2, probabilities: [40, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Sneasel, flawless_ivs: 3, probabilities: [0, 25, 30, 0, 0] },
  DenEncounter { species: types::Species::Sneasel, flawless_ivs: 3, probabilities: [0, 20, 25, 0, 0] },
  DenEncounter { species: types::Species::Thievul, flawless_ivs: 4, probabilities: [0, 0, 25, 25, 0] },
  DenEncounter { species: types::Species::Liepard, flawless_ivs: 4, probabilities: [0, 0, 15, 25, 0] },
  DenEncounter { species: types::Species::Absol, flawless_ivs: 5, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Grimmsnarl, flawless_ivs: 5, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Weavile, flawless_ivs: 5, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Absol, flawless_ivs: 5, probabilities: [0, 0, 0, 0, 20] },
  DenEncounter { species: types::Species::Grimmsnarl, flawless_ivs: 5, probabilities: [0, 0, 0, 0, 15] },
];

#[rustfmt::skip]
const NEST_7EA57D4A1EF4C796: DenEncounters = [
  DenEncounter { species: types::Species::Audino, flawless_ivs: 4, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Aron, flawless_ivs: 1, probabilities: [60, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Durant, flawless_ivs: 1, probabilities: [40, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Aron, flawless_ivs: 2, probabilities: [0, 25, 30, 0, 0] },
  DenEncounter { species: types::Species::Beldum, flawless_ivs: 2, probabilities: [0, 20, 25, 0, 0] },
  DenEncounter { species: types::Species::Lairon, flawless_ivs: 3, probabilities: [0, 0, 25, 25, 0] },
  DenEncounter { species: types::Species::Metang, flawless_ivs: 3, probabilities: [0, 0, 15, 25, 0] },
  DenEncounter { species: types::Species::Corviknight, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 25] },
  DenEncounter { species: types::Species::Durant, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Copperajah, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Aggron, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Aggron, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
];

#[rustfmt::skip]
const NEST_E0236C3B91EDBEBB: DenEncounters = [
  DenEncounter { species: types::Species::Delibird, flawless_ivs: 5, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Aron, flawless_ivs: 2, probabilities: [60, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Meowth, flawless_ivs: 2, probabilities: [40, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Durant, flawless_ivs: 3, probabilities: [0, 25, 30, 0, 0] },
  DenEncounter { species: types::Species::Lairon, flawless_ivs: 3, probabilities: [0, 20, 25, 0, 0] },
  DenEncounter { species: types::Species::Perrserker, flawless_ivs: 4, probabilities: [0, 0, 25, 25, 0] },
  DenEncounter { species: types::Species::Perrserker, flawless_ivs: 4, probabilities: [0, 0, 15, 25, 0] },
  DenEncounter { species: types::Species::Copperajah, flawless_ivs: 5, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Aggron, flawless_ivs: 5, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Metagross, flawless_ivs: 5, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Metagross, flawless_ivs: 5, probabilities: [0, 0, 0, 0, 20] },
  DenEncounter { species: types::Species::Copperajah, flawless_ivs: 5, probabilities: [0, 0, 0, 0, 15] },
];

#[rustfmt::skip]
const NEST_C862667FC72EE059: DenEncounters = [
  DenEncounter { species: types::Species::Audino, flawless_ivs: 4, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Cleffa, flawless_ivs: 1, probabilities: [60, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Carbink, flawless_ivs: 1, probabilities: [40, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Hatenna, flawless_ivs: 2, probabilities: [0, 25, 30, 0, 0] },
  DenEncounter { species: types::Species::Cleffa, flawless_ivs: 2, probabilities: [0, 20, 25, 0, 0] },
  DenEncounter { species: types::Species::Hattrem, flawless_ivs: 3, probabilities: [0, 0, 25, 25, 0] },
  DenEncounter { species: types::Species::Clefairy, flawless_ivs: 3, probabilities: [0, 0, 15, 25, 0] },
  DenEncounter { species: types::Species::Carbink, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 25] },
  DenEncounter { species: types::Species::Carbink, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Clefable, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Whimsicott, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Hatterene, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
];

#[rustfmt::skip]
const NEST_72F9D87337338120: DenEncounters = [
  DenEncounter { species: types::Species::Delibird, flawless_ivs: 5, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Carbink, flawless_ivs: 2, probabilities: [60, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Cottonee, flawless_ivs: 2, probabilities: [40, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Clefairy, flawless_ivs: 3, probabilities: [0, 25, 30, 0, 0] },
  DenEncounter { species: types::Species::Carbink, flawless_ivs: 3, probabilities: [0, 20, 25, 0, 0] },
  DenEncounter { species: types::Species::Carbink, flawless_ivs: 4, probabilities: [0, 0, 25, 25, 0] },
  DenEncounter { species: types::Species::Whimsicott, flawless_ivs: 4, probabilities: [0, 0, 15, 25, 0] },
  DenEncounter { species: types::Species::Weezing, flawless_ivs: 5, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Hatterene, flawless_ivs: 5, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Clefable, flawless_ivs: 5, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Weezing, flawless_ivs: 5, probabilities: [0, 0, 0, 0, 20] },
  DenEncounter { species: types::Species::Hatterene, flawless_ivs: 5, probabilities: [0, 0, 0, 0, 15] },
];

#[rustfmt::skip]
const NEST_F01DFB231A467C06: DenEncounters = [
  DenEncounter { species: types::Species::Audino, flawless_ivs: 4, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Sinistea, flawless_ivs: 1, probabilities: [60, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Sinistea, flawless_ivs: 1, probabilities: [40, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Sinistea, flawless_ivs: 2, probabilities: [0, 25, 30, 0, 0] },
  DenEncounter { species: types::Species::Sinistea, flawless_ivs: 2, probabilities: [0, 20, 25, 0, 0] },
  DenEncounter { species: types::Species::Sinistea, flawless_ivs: 3, probabilities: [0, 0, 20, 26, 0] },
  DenEncounter { species: types::Species::Sinistea, flawless_ivs: 3, probabilities: [0, 0, 17, 25, 0] },
  DenEncounter { species: types::Species::Sinistea, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 27] },
  DenEncounter { species: types::Species::Sinistea, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 23] },
  DenEncounter { species: types::Species::Sinistea, flawless_ivs: 4, probabilities: [0, 0, 0, 10, 20] },
  DenEncounter { species: types::Species::Sinistea, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 20] },
  DenEncounter { species: types::Species::Sinistea, flawless_ivs: 4, probabilities: [0, 0, 3, 4, 5] },
];

#[rustfmt::skip]
const NEST_8B5A3178AE3F236B: DenEncounters = [
  DenEncounter { species: types::Species::Delibird, flawless_ivs: 5, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Sinistea, flawless_ivs: 2, probabilities: [99, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::Sinistea, flawless_ivs: 2, probabilities: [0, 50, 0, 0, 0] },
  DenEncounter { species: types::Species::Sinistea, flawless_ivs: 3, probabilities: [0, 27, 0, 0, 0] },
  DenEncounter { species: types::Species::Sinistea, flawless_ivs: 3, probabilities: [0, 20, 0, 0, 0] },
  DenEncounter { species: types::Species::Sinistea, flawless_ivs: 4, probabilities: [0, 0, 90, 0, 0] },
  DenEncounter { species: types::Species::Sinistea, flawless_ivs: 4, probabilities: [0, 0, 0, 73, 0] },
  DenEncounter { species: types::Species::Sinistea, flawless_ivs: 5, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Sinistea, flawless_ivs: 5, probabilities: [1, 3, 5, 7, 0] },
  DenEncounter { species: types::Species::Polteageist, flawless_ivs: 5, probabilities: [0, 0, 0, 0, 51] },
  DenEncounter { species: types::Species::Polteageist, flawless_ivs: 5, probabilities: [0, 0, 0, 0, 9] },
  DenEncounter { species: types::Species::Alcremie, flawless_ivs: 5, probabilities: [0, 0, 0, 0, 15] },
];

#[rustfmt::skip]
const NEST_E78D0A25D0C67A32: DenEncounters = [
  DenEncounter { species: types::Species::Audino, flawless_ivs: 4, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Eevee, flawless_ivs: 1, probabilities: [50, 50, 0, 0, 0] },
  DenEncounter { species: types::Species::Eevee, flawless_ivs: 2, probabilities: [40, 30, 45, 21, 3] },
  DenEncounter { species: types::Species::Eevee, flawless_ivs: 3, probabilities: [10, 20, 18, 10, 4] },
  DenEncounter { species: types::Species::Flareon, flawless_ivs: 4, probabilities: [0, 0, 4, 8, 11] },
  DenEncounter { species: types::Species::Jolteon, flawless_ivs: 4, probabilities: [0, 0, 4, 8, 11] },
  DenEncounter { species: types::Species::Vaporeon, flawless_ivs: 4, probabilities: [0, 0, 4, 8, 11] },
  DenEncounter { species: types::Species::Espeon, flawless_ivs: 4, probabilities: [0, 0, 4, 8, 11] },
  DenEncounter { species: types::Species::Umbreon, flawless_ivs: 4, probabilities: [0, 0, 4, 8, 11] },
  DenEncounter { species: types::Species::Leafeon, flawless_ivs: 4, probabilities: [0, 0, 4, 8, 11] },
  DenEncounter { species: types::Species::Glaceon, flawless_ivs: 4, probabilities: [0, 0, 4, 8, 11] },
  DenEncounter { species: types::Species::Sylveon, flawless_ivs: 4, probabilities: [0, 0, 4, 8, 11] },
];

#[rustfmt::skip]
const NEST_BDF065BB6332909F: DenEncounters = [
  DenEncounter { species: types::Species::Delibird, flawless_ivs: 5, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Eevee, flawless_ivs: 2, probabilities: [50, 50, 0, 0, 0] },
  DenEncounter { species: types::Species::Eevee, flawless_ivs: 3, probabilities: [40, 30, 45, 21, 3] },
  DenEncounter { species: types::Species::Eevee, flawless_ivs: 4, probabilities: [10, 20, 18, 10, 4] },
  DenEncounter { species: types::Species::Flareon, flawless_ivs: 5, probabilities: [0, 0, 4, 8, 11] },
  DenEncounter { species: types::Species::Jolteon, flawless_ivs: 5, probabilities: [0, 0, 4, 8, 11] },
  DenEncounter { species: types::Species::Vaporeon, flawless_ivs: 5, probabilities: [0, 0, 4, 8, 11] },
  DenEncounter { species: types::Species::Espeon, flawless_ivs: 5, probabilities: [0, 0, 4, 8, 11] },
  DenEncounter { species: types::Species::Umbreon, flawless_ivs: 5, probabilities: [0, 0, 4, 8, 11] },
  DenEncounter { species: types::Species::Leafeon, flawless_ivs: 5, probabilities: [0, 0, 4, 8, 11] },
  DenEncounter { species: types::Species::Glaceon, flawless_ivs: 5, probabilities: [0, 0, 4, 8, 11] },
  DenEncounter { species: types::Species::Sylveon, flawless_ivs: 5, probabilities: [0, 0, 4, 8, 11] },
];

#[rustfmt::skip]
const NEST_58C3011EDA59EA53: DenEncounters = [
  DenEncounter { species: types::Species::Audino, flawless_ivs: 4, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Omanyte, flawless_ivs: 1, probabilities: [60, 30, 0, 0, 0] },
  DenEncounter { species: types::Species::Anorith, flawless_ivs: 1, probabilities: [40, 25, 0, 0, 0] },
  DenEncounter { species: types::Species::Tyrunt, flawless_ivs: 2, probabilities: [0, 25, 30, 0, 0] },
  DenEncounter { species: types::Species::Amaura, flawless_ivs: 2, probabilities: [0, 20, 25, 0, 0] },
  DenEncounter { species: types::Species::Armaldo, flawless_ivs: 3, probabilities: [0, 0, 25, 25, 0] },
  DenEncounter { species: types::Species::Cradily, flawless_ivs: 3, probabilities: [0, 0, 15, 25, 0] },
  DenEncounter { species: types::Species::Omastar, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 25] },
  DenEncounter { species: types::Species::Armaldo, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Tyrantrum, flawless_ivs: 4, probabilities: [0, 0, 0, 15, 20] },
  DenEncounter { species: types::Species::Aurorus, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
  DenEncounter { species: types::Species::Aerodactyl, flawless_ivs: 4, probabilities: [0, 0, 0, 0, 15] },
];

#[rustfmt::skip]
const NEST_B4DBD8428706D1C2: DenEncounters = [
  DenEncounter { species: types::Species::Delibird, flawless_ivs: 5, probabilities: [0, 0, 5, 5, 5] },
  DenEncounter { species: types::Species::Omanyte, flawless_ivs: 2, probabilities: [100, 100, 0, 0, 0] },
  DenEncounter { species: types::Species::Omastar, flawless_ivs: 2, probabilities: [0, 0, 15, 0, 0] },
  DenEncounter { species: types::Species::Aerodactyl, flawless_ivs: 3, probabilities: [0, 0, 40, 0, 0] },
  DenEncounter { species: types::Species::Arctozolt, flawless_ivs: 3, probabilities: [0, 0, 20, 0, 0] },
  DenEncounter { species: types::Species::Dracozolt, flawless_ivs: 4, probabilities: [0, 0, 20, 30, 0] },
  DenEncounter { species: types::Species::Dracovish, flawless_ivs: 4, probabilities: [0, 0, 0, 7, 0] },
  DenEncounter { species: types::Species::Aerodactyl, flawless_ivs: 5, probabilities: [0, 0, 0, 21, 15] },
  DenEncounter { species: types::Species::Dracozolt, flawless_ivs: 5, probabilities: [0, 0, 0, 0, 30] },
  DenEncounter { species: types::Species::Dracovish, flawless_ivs: 5, probabilities: [0, 0, 0, 0, 10] },
  DenEncounter { species: types::Species::Arctozolt, flawless_ivs: 5, probabilities: [0, 0, 0, 30, 30] },
  DenEncounter { species: types::Species::Arctovish, flawless_ivs: 5, probabilities: [0, 0, 0, 7, 10] },
];

#[rustfmt::skip]
const NEST_EVENT_PLACEHOLDER: DenEncounters = [
  DenEncounter { species: types::Species::None, flawless_ivs: 0, probabilities: [0, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::None, flawless_ivs: 0, probabilities: [0, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::None, flawless_ivs: 0, probabilities: [0, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::None, flawless_ivs: 0, probabilities: [0, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::None, flawless_ivs: 0, probabilities: [0, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::None, flawless_ivs: 0, probabilities: [0, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::None, flawless_ivs: 0, probabilities: [0, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::None, flawless_ivs: 0, probabilities: [0, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::None, flawless_ivs: 0, probabilities: [0, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::None, flawless_ivs: 0, probabilities: [0, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::None, flawless_ivs: 0, probabilities: [0, 0, 0, 0, 0] },
  DenEncounter { species: types::Species::None, flawless_ivs: 0, probabilities: [0, 0, 0, 0, 0] },
];

pub fn get_encounters(nest: Nest) -> &'static DenEncounters {
    match nest {
        Nest::EventPlaceholder => &NEST_EVENT_PLACEHOLDER,
        Nest::N12ad4e9a799417a5 => &NEST_12AD4E9A799417A5,
        Nest::N173efe56dc5df220 => &NEST_173EFE56DC5DF220,
        Nest::N173eff56dc5df3d3 => &NEST_173EFF56DC5DF3D3,
        Nest::N173f0056dc5df586 => &NEST_173F0056DC5DF586,
        Nest::N173f0156dc5df739 => &NEST_173F0156DC5DF739,
        Nest::N173f0256dc5df8ec => &NEST_173F0256DC5DF8EC,
        Nest::N173f0356dc5dfa9f => &NEST_173F0356DC5DFA9F,
        Nest::N173f0456dc5dfc52 => &NEST_173F0456DC5DFC52,
        Nest::N173f0556dc5dfe05 => &NEST_173F0556DC5DFE05,
        Nest::N173f0656dc5dffb8 => &NEST_173F0656DC5DFFB8,
        Nest::N173f0756dc5e016b => &NEST_173F0756DC5E016B,
        Nest::N17428156dc610690 => &NEST_17428156DC610690,
        Nest::N17428256dc610843 => &NEST_17428256DC610843,
        Nest::N17428356dc6109f6 => &NEST_17428356DC6109F6,
        Nest::N17428556dc610d5c => &NEST_17428556DC610D5C,
        Nest::N17428656dc610f0f => &NEST_17428656DC610F0F,
        Nest::N17428756dc6110c2 => &NEST_17428756DC6110C2,
        Nest::N17428856dc611275 => &NEST_17428856DC611275,
        Nest::N17428b56dc61178e => &NEST_17428B56DC61178E,
        Nest::N17428c56dc611941 => &NEST_17428C56DC611941,
        Nest::N17458456dc634180 => &NEST_17458456DC634180,
        Nest::N17458556dc634333 => &NEST_17458556DC634333,
        Nest::N17458656dc6344e6 => &NEST_17458656DC6344E6,
        Nest::N17458756dc634699 => &NEST_17458756DC634699,
        Nest::N17458856dc63484c => &NEST_17458856DC63484C,
        Nest::N17458956dc6349ff => &NEST_17458956DC6349FF,
        Nest::N17458a56dc634bb2 => &NEST_17458A56DC634BB2,
        Nest::N17458b56dc634d65 => &NEST_17458B56DC634D65,
        Nest::N17459256dc63594a => &NEST_17459256DC63594A,
        Nest::N17459356dc635afd => &NEST_17459356DC635AFD,
        Nest::N17490756dc6655f0 => &NEST_17490756DC6655F0,
        Nest::N17490856dc6657a3 => &NEST_17490856DC6657A3,
        Nest::N17490f56dc666388 => &NEST_17490F56DC666388,
        Nest::N17491056dc66653b => &NEST_17491056DC66653B,
        Nest::N17491156dc6666ee => &NEST_17491156DC6666EE,
        Nest::N17491256dc6668a1 => &NEST_17491256DC6668A1,
        Nest::N17491356dc666a54 => &NEST_17491356DC666A54,
        Nest::N17491456dc666c07 => &NEST_17491456DC666C07,
        Nest::N17491556dc666dba => &NEST_17491556DC666DBA,
        Nest::N17491656dc666f6d => &NEST_17491656DC666F6D,
        Nest::N17501a56dc6c94e7 => &NEST_17501A56DC6C94E7,
        Nest::N17501b56dc6c969a => &NEST_17501B56DC6C969A,
        Nest::N17501c56dc6c984d => &NEST_17501C56DC6C984D,
        Nest::N17d327792698d15f => &NEST_17D327792698D15F,
        Nest::N1928030ad989ad02 => &NEST_1928030AD989AD02,
        Nest::N1c1962488c012ee8 => &NEST_1C1962488C012EE8,
        Nest::N21f6c865b3513bab => &NEST_21F6C865B3513BAB,
        Nest::N21f6c965b3513d5e => &NEST_21F6C965B3513D5E,
        Nest::N2640fa844b19c3cf => &NEST_2640FA844B19C3CF,
        Nest::N277effbe0b116e4a => &NEST_277EFFBE0B116E4A,
        Nest::N2998f2424d0353eb => &NEST_2998F2424D0353EB,
        Nest::N2cd8cf9a88739f98 => &NEST_2CD8CF9A88739F98,
        Nest::N314acb827c75109 => &NEST_314ACB827C75109,
        Nest::N316e6b5e74bc7aa3 => &NEST_316E6B5E74BC7AA3,
        Nest::N3a41c5c485d3edee => &NEST_3A41C5C485D3EDEE,
        Nest::N3b3c0865d15b0aca => &NEST_3B3C0865D15B0ACA,
        Nest::N3d2f6b02fc6dd797 => &NEST_3D2F6B02FC6DD797,
        Nest::N3d6f1fcb3898d356 => &NEST_3D6F1FCB3898D356,
        Nest::N3ea9df3b7b2b5990 => &NEST_3EA9DF3B7B2B5990,
        Nest::N40bdbe4f3bcbac86 => &NEST_40BDBE4F3BCBAC86,
        Nest::N422f95fb66a95706 => &NEST_422F95FB66A95706,
        Nest::N4257e30e1c471230 => &NEST_4257E30E1C471230,
        Nest::N4257e40e1c4713e3 => &NEST_4257E40E1C4713E3,
        Nest::N4257e50e1c471596 => &NEST_4257E50E1C471596,
        Nest::N4257ea0e1c471e15 => &NEST_4257EA0E1C471E15,
        Nest::N42b21efc37c7b974 => &NEST_42B21EFC37C7B974,
        Nest::N450097d99cf5626c => &NEST_450097D99CF5626C,
        Nest::N450098d99cf5641f => &NEST_450098D99CF5641F,
        Nest::N45009bd99cf56938 => &NEST_45009BD99CF56938,
        Nest::N45009cd99cf56aeb => &NEST_45009CD99CF56AEB,
        Nest::N45009dd99cf56c9e => &NEST_45009DD99CF56C9E,
        Nest::N45009ed99cf56e51 => &NEST_45009ED99CF56E51,
        Nest::N4500a0d99cf571b7 => &NEST_4500A0D99CF571B7,
        Nest::N4500a1d99cf5736a => &NEST_4500A1D99CF5736A,
        Nest::N4500a2d99cf5751d => &NEST_4500A2D99CF5751D,
        Nest::N45041ed99cf87da8 => &NEST_45041ED99CF87DA8,
        Nest::N45041fd99cf87f5b => &NEST_45041FD99CF87F5B,
        Nest::N450420d99cf8810e => &NEST_450420D99CF8810E,
        Nest::N450421d99cf882c1 => &NEST_450421D99CF882C1,
        Nest::N450422d99cf88474 => &NEST_450422D99CF88474,
        Nest::N450423d99cf88627 => &NEST_450423D99CF88627,
        Nest::N450424d99cf887da => &NEST_450424D99CF887DA,
        Nest::N450425d99cf8898d => &NEST_450425D99CF8898D,
        Nest::N47a5d8b98dd573ab => &NEST_47A5D8B98DD573AB,
        Nest::N4c12cee7784c8b8 => &NEST_4C12CEE7784C8B8,
        Nest::N4f1e561dd73ed3d8 => &NEST_4F1E561DD73ED3D8,
        Nest::N4f1e581dd73ed73e => &NEST_4F1E581DD73ED73E,
        Nest::N4f1e591dd73ed8f1 => &NEST_4F1E591DD73ED8F1,
        Nest::N4f1e5a1dd73edaa4 => &NEST_4F1E5A1DD73EDAA4,
        Nest::N4f1e5b1dd73edc57 => &NEST_4F1E5B1DD73EDC57,
        Nest::N4f1e5c1dd73ede0a => &NEST_4F1E5C1DD73EDE0A,
        Nest::N4f1e5d1dd73edfbd => &NEST_4F1E5D1DD73EDFBD,
        Nest::N50eaf4685fa07085 => &NEST_50EAF4685FA07085,
        Nest::N52a7dfe87897d15d => &NEST_52A7DFE87897D15D,
        Nest::N53441b80e563ef1f => &NEST_53441B80E563EF1F,
        Nest::N5584521f1e549486 => &NEST_5584521F1E549486,
        Nest::N55846e1f1e54c41a => &NEST_55846E1F1E54C41A,
        Nest::N55e4467f01ec60bb => &NEST_55E4467F01EC60BB,
        Nest::N58c3011eda59ea53 => &NEST_58C3011EDA59EA53,
        Nest::N5b72bfac0ff3f885 => &NEST_5B72BFAC0FF3F885,
        Nest::N5c9a35ca819b38c8 => &NEST_5C9A35CA819B38C8,
        Nest::N60ef1d711ae30cf0 => &NEST_60EF1D711AE30CF0,
        Nest::N685dad2aaedbca48 => &NEST_685DAD2AAEDBCA48,
        Nest::N685db02aaedbcf61 => &NEST_685DB02AAEDBCF61,
        Nest::N6aebee2a2d6d8470 => &NEST_6AEBEE2A2D6D8470,
        Nest::N6b37a94863bf68c0 => &NEST_6B37A94863BF68C0,
        Nest::N6c364ecc3616af63 => &NEST_6C364ECC3616AF63,
        Nest::N6d015b7858eb5119 => &NEST_6D015B7858EB5119,
        Nest::N6e6b46639f77f0c8 => &NEST_6E6B46639F77F0C8,
        Nest::N6f948f09933cdfc => &NEST_6F948F09933CDFC,
        Nest::N7288f0346fd3cdd8 => &NEST_7288F0346FD3CDD8,
        Nest::N72f9d87337338120 => &NEST_72F9D87337338120,
        Nest::N75319113c8c3b924 => &NEST_75319113C8C3B924,
        Nest::N779e9eb99c1292c => &NEST_779E9EB99C1292C,
        Nest::N79b25a4f80255a38 => &NEST_79B25A4F80255A38,
        Nest::N7ea57d4a1ef4c796 => &NEST_7EA57D4A1EF4C796,
        Nest::N89955cc3a594e51a => &NEST_89955CC3A594E51A,
        Nest::N8b5a3178ae3f236b => &NEST_8B5A3178AE3F236B,
        Nest::N93a637943a964e41 => &NEST_93A637943A964E41,
        Nest::N9ab5727f28c3d593 => &NEST_9AB5727F28C3D593,
        Nest::N9d415f6a7a841dd9 => &NEST_9D415F6A7A841DD9,
        Nest::N9fdf11a0cde96b2e => &NEST_9FDF11A0CDE96B2E,
        Nest::Na178d4769765abac => &NEST_A178D4769765ABAC,
        Nest::Na23ec426e4e9430a => &NEST_A23EC426E4E9430A,
        Nest::Na5696e4aa8d625a => &NEST_A5696E4AA8D625A,
        Nest::Nae57b2a84974c3a1 => &NEST_AE57B2A84974C3A1,
        Nest::Nb0c9af2202b0a19e => &NEST_B0C9AF2202B0A19E,
        Nest::Nb20a5ed251cd0456 => &NEST_B20A5ED251CD0456,
        Nest::Nb4dbd8428706d1c2 => &NEST_B4DBD8428706D1C2,
        Nest::Nb8a5e528bfee71bc => &NEST_B8A5E528BFEE71BC,
        Nest::Nba805367100fc4ac => &NEST_BA805367100FC4AC,
        Nest::Nba805467100fc65f => &NEST_BA805467100FC65F,
        Nest::Nba805767100fcb78 => &NEST_BA805767100FCB78,
        Nest::Nba805867100fcd2b => &NEST_BA805867100FCD2B,
        Nest::Nba805967100fcede => &NEST_BA805967100FCEDE,
        Nest::Nba805a67100fd091 => &NEST_BA805A67100FD091,
        Nest::Nba805c67100fd3f7 => &NEST_BA805C67100FD3F7,
        Nest::Nba805d67100fd5aa => &NEST_BA805D67100FD5AA,
        Nest::Nba805e67100fd75d => &NEST_BA805E67100FD75D,
        Nest::Nba83d8671012dc82 => &NEST_BA83D8671012DC82,
        Nest::Nba83d9671012de35 => &NEST_BA83D9671012DE35,
        Nest::Nba83da671012dfe8 => &NEST_BA83DA671012DFE8,
        Nest::Nba83db671012e19b => &NEST_BA83DB671012E19B,
        Nest::Nba83dc671012e34e => &NEST_BA83DC671012E34E,
        Nest::Nba83dd671012e501 => &NEST_BA83DD671012E501,
        Nest::Nba83de671012e6b4 => &NEST_BA83DE671012E6B4,
        Nest::Nba83df671012e867 => &NEST_BA83DF671012E867,
        Nest::Nba83e0671012ea1a => &NEST_BA83E0671012EA1A,
        Nest::Nba83e1671012ebcd => &NEST_BA83E1671012EBCD,
        Nest::Nba8745671015cb90 => &NEST_BA8745671015CB90,
        Nest::Nba8746671015cd43 => &NEST_BA8746671015CD43,
        Nest::Nba8747671015cef6 => &NEST_BA8747671015CEF6,
        Nest::Nba8748671015d0a9 => &NEST_BA8748671015D0A9,
        Nest::Nba8749671015d25c => &NEST_BA8749671015D25C,
        Nest::Nba874a671015d40f => &NEST_BA874A671015D40F,
        Nest::Nba874b671015d5c2 => &NEST_BA874B671015D5C2,
        Nest::Nba874c671015d775 => &NEST_BA874C671015D775,
        Nest::Nba874f671015dc8e => &NEST_BA874F671015DC8E,
        Nest::Nba8750671015de41 => &NEST_BA8750671015DE41,
        Nest::Nba8a496710180833 => &NEST_BA8A496710180833,
        Nest::Nba8a4c6710180d4c => &NEST_BA8A4C6710180D4C,
        Nest::Nba8a4d6710180eff => &NEST_BA8A4D6710180EFF,
        Nest::Nba8a4e67101810b2 => &NEST_BA8A4E67101810B2,
        Nest::Nba8a4f6710181265 => &NEST_BA8A4F6710181265,
        Nest::Nbc3d01fff751cde4 => &NEST_BC3D01FFF751CDE4,
        Nest::Nbdf065bb6332909f => &NEST_BDF065BB6332909F,
        Nest::Nc63dec8a65b5c540 => &NEST_C63DEC8A65B5C540,
        Nest::Nc80756327d5de060 => &NEST_C80756327D5DE060,
        Nest::Nc862667fc72ee059 => &NEST_C862667FC72EE059,
        Nest::Nc88b8a5990a8ea5c => &NEST_C88B8A5990A8EA5C,
        Nest::Nc8ea8c1618ab0a58 => &NEST_C8EA8C1618AB0A58,
        Nest::Nd8f0ffcde5822363 => &NEST_D8F0FFCDE5822363,
        Nest::Nd8f100cde5822516 => &NEST_D8F100CDE5822516,
        Nest::Ndb8629cba3383296 => &NEST_DB8629CBA3383296,
        Nest::Ndf017f3fefba2704 => &NEST_DF017F3FEFBA2704,
        Nest::Ne0236c3b91edbebb => &NEST_E0236C3B91EDBEBB,
        Nest::Ne234e939402a736b => &NEST_E234E939402A736B,
        Nest::Ne2c6e5e725342f4a => &NEST_E2C6E5E725342F4A,
        Nest::Ne78d0a25d0c67a32 => &NEST_E78D0A25D0C67A32,
        Nest::Nea4c3915ea6f95a0 => &NEST_EA4C3915EA6F95A0,
        Nest::Nf01dfb231a467c06 => &NEST_F01DFB231A467C06,
        Nest::Nf4a830850f51d034 => &NEST_F4A830850F51D034,
        Nest::Nf6389ad0bc9aaeb => &NEST_F6389AD0BC9AAEB,
        Nest::Nf9222e1acdf486e8 => &NEST_F9222E1ACDF486E8,
        Nest::Nf9280759d6cc62a3 => &NEST_F9280759D6CC62A3,
        Nest::Nf9d3242b837d627e => &NEST_F9D3242B837D627E,
        Nest::Nfe9695f9799c6258 => &NEST_FE9695F9799C6258,
        Nest::Nfe9696f9799c640b => &NEST_FE9696F9799C640B,
        Nest::Nfe9697f9799c65be => &NEST_FE9697F9799C65BE,
        Nest::Nfe969cf9799c6e3d => &NEST_FE969CF9799C6E3D,
    }
}

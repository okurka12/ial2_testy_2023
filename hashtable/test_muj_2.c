/* tenhle test se spusti samostatne je tady hromada assertu */

#include <assert.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "hashtable.h"

/* tady dej 1 jestli chces videt prubeh testu */
#define verbose 0

/* pole 100 ruznych klicu (muzes pridat jestli chces) */
const unsigned int words_start = __LINE__; char *words[] = {
    "homeschooling",
    "equivocally",
    "Saratov's",
    "apostleship's",
    "Clint",
    "lithuania",
    "ticklish",
    "befringes",
    "incloser's",
    "Milazzo",
    "pretending",
    "consortism",
    "sterilities",
    "riotry",
    "Bipontine",
    "curveballing",
    "Oreo",
    "Acrocarpi's",
    "aeroembolism's",
    "Maximilianus's",
    "mouthing's",
    "gramarye's",
    "sevastopol",
    "salsuginose",
    "Francophobe's",
    "relier's",
    "underbarber",
    "butterfly's",
    "cornification",
    "serviceman",
    "britts",
    "presuppositional",
    "survivoress",
    "Neoclassicisms",
    "flatbottom",
    "ancienter",
    "pyotherapy",
    "nontemptation",
    "occipitally",
    "quillet",
    "Fascist",
    "pretracing",
    "parcellize",
    "humanism",
    "hydroextractor's",
    "tanzib",
    "sciaena",
    "avenage",
    "Antisi",
    "Achaeus's",
    "tagilite",
    "ana",
    "proteinuria",
    "abampere's",
    "berkelium",
    "Ocaml",
    "Cocceianism",
    "olacad",
    "raves",
    "Cervulus's",
    "spillages",
    "Nenney",
    "curmurrings",
    "stereoscopists",
    "Berycomorphi",
    "anatomicopathologic",
    "corrigenda's",
    "lowlanders",
    "Bahreini's",
    "Jacksontown",
    "folkmotes",
    "infantility",
    "overdesigned",
    "beautying",
    "pressureless",
    "anatta's",
    "eutaxitic",
    "dunams",
    "Yeung's",
    "Ensenada",
    "pouldered",
    "persister",
    "herden",
    "provings",
    "realtie",
    "Monogynia's",
    "optimalities",
    "seaman's",
    "pretermitting",
    "caky",
    "Faith's",
    "Kumler",
    "mousiness's",
    "universeful",
    "albertype",
    "henotheist's",
    "Aubry's",
    "bodkin",
    "unilocularity",
    "Erythroxylum's",
    "spilehole",
    "sonneteer's",
    "phytoplankter's",
    "outsleep",
    "nea",
    "meh",
    "Düsseldorf's",
    "loudering",
    "Rhizostomata",
    "rollcollar's",
    "unthinking",
    "Africanist",
    "bergfalls",
    "Gault",
    "ragbolt",
    "Cerberi",
    "suffrutescent",
    "boughy",
    "racemose",
    "Bothwell",
    "anodontia",
    "defibrillation",
    "ginhouses",
    "martinetish",
    "evonymus's",
    "Assiniboin",
    "puerpera",
    "Helmand",
    "Louisville",
    "softer",
    "heliculturalist",
    "Arundel",
    "Crocus",
    "imperviableness",
    "typhoons",
    "aftertaste's",
    "Tatarian",
    "antirachitic's",
    "spanopnea",
    "norcamphane",
    "vraisemblances",
    "Nuculacea",
    "ichthyosaurid",
    "censuses",
    "apomicts",
    "microbars",
    "instructible",
    "microspherical",
    "crapehanging",
    "Marcionism",
    "nonnihilistic",
    "cotised",
    "parataxes",
    "contadino's",
    "prestatistical",
    "nettlewort",
    "scrawly",
    "ganched",
    "ophthalmodynamometer",
    "amontillados",
    "lowne",
    "Sinto's",
    "Skagway",
    "myxoenchondroma",
    "blaeness",
    "zihar",
    "poephila",
    "alcoate",
    "boondocks",
    "afoul",
    "symptomizing",
    "sagoins",
    "unplaying",
    "whales's",
    "forfairn",
    "frowier",
    "Skaneateles",
    "carrys",
    "schorlous",
    "photocatalysis",
    "semidivine",
    "broncho",
    "Tecmessa's",
    "rejuvenizing",
    "perdus",
    "coffinite",
    "Polypifera's",
    "irretentiveness",
    "Marlie's",
    "compendiary",
    "disponee",
    "achenia",
    "drazels",
    "sacheted",
    "stethoscopist's",
    "semitorpid",
    "homopteran",
    "stomatophorous",
    "enslumber",
    "halituses",
    "sexological",
    "unicyclist's",
    "bellamoures",
    "supergroup's",
    "circuitousness's",
    "talahib",
    "triploids",
    "crescentwise",
    "Devonic",
    "puncticulose",
    "cleansings",
    "aspersive",
    "Madelaine's",
    "harpoonlike",
    "Eugen's",
    "sufferable",
    "athermancies",
    "Jeeze's",
    "gladrags",
    "Hardunn",
    "Roszak's",
    "turpid",
    "xylotile",
    "Yuman",
    "subducted",
    "Lothario",
    "satoris",
    "unhumored",
    "surculous",
    "sanguineousness",
    "bombo",
    "talbotype",
    "illiberalizes",
    "historicized",
    "barbicel's",
    "marshiness",
    "letterspaced",
    "canto's",
    "Ermey",
    "epidermises",
    "theologastric",
    "disadvantaging",
    "peckly",
    "dodkin's",
    "cyanophil",
    "Littrow",
    "Teutonomania's",
    "physis",
    "Amasa's",
    "frutify",
    "Ancyloceras",
    "festooned",
    "amyotrophia",
    "caramba",
    "dooles",
    "Admiral",
    "physicopsychical",
    "hambones",
    "scramjet's",
    "cowfeeders",
    "methoxychlor's",
    "Lovett's",
    "Atymnius",
    "Listera",
    "olé's",
    "cukes",
    "isorosindone",
    "halfhourly",
    "vapulating",
    "Wendt",
    "Tidioute",
    "evigilation",
    "undershorts",
    "Cuzzart's",
    "victrices",
    "hetherward",
    "Paludicella",
    "bubblegum's",
    "Colliers",
    "unripplingly",
    "unilateralism",
    "Antone's",
    "tunneries",
    "Anomalon's",
    "tabularly",
    "Hants",
    "templet",
    "blanchimeter",
    "microphagocyte",
    "Naubinway's",
    "unallusiveness",
    "Enzed's",
    "Alnascharism",
    "fourpence's",
    "toddlerhood's",
    "superenergetically",
    "debasednesses",
    "Bagobo",
    "Italomania's",
    "dearticulation",
    "nontheocratic",
    "overslur",
    "condolers",
    "misbrands",
    "Meltonian",
    "Hedda's",
    "pint",
    "muskellunges",
    "calpul",
    "sporangiolum",
    "insufflations",
    "rabidities",
    "Spense",
    "corosif",
    "mastodon's",
    "Schmitz",
    "swelltoad",
    "ichthyodorulite",
    "Gourdine",
    "pliotron's",
    "nonascendency",
    "apopyle",
    "obliquation",
    "cynghanedd",
    "prenticeships",
    "Broaddus",
    "noncumulatively",
    "Lockean",
    "fadingness",
    "planography",
    "attainers",
    "lemminglike",
    "Carrere",
    "Joshia",
    "overspinning",
    "aphrasia",
    "Kaffirs",
    "khansamahs",
    "nonadvertence",
    "Aidoneus's",
    "thingumabob",
    "nonsubstantiveness",
    "tralaticiary",
    "solicities",
    "buirdlier",
    "recompile",
    "Lillian",
    "acetylacetone",
    "Guesde",
    "commonalty",
    "poussies",
    "rafales",
    "Pipra's",
    "subtilities",
    "lasiurus",
    "bobbling",
    "Saadi",
    "hydramine",
    "Felicie",
    "horn",
    "discoplacental",
    "outgive",
    "unswathable",
    "intoxicantly",
    "Amintore",
    "unrecalcitrant",
    "valeur",
    "pseudonational",
    "acute's",
    "moric",
    "Lollardism",
    "Damalas",
    "drymarchon",
    "formably",
    "Tula",
    "alphosis's",
    "unavenued",
    "phalangists",
    "barroom's",
    "quinquenerved",
    "brechams",
    "leafiest",
    "Livistona's",
    "bultell",
    "powdered",
    "archenemy's",
    "sundog's",
    "osteogenies",
    "Profant",
    "Katherin's",
    "brails",
    "Roath's",
    "intracavitary",
    "hachiman",
    "sulphamate",
    "limuloid's",
    "scenewright",
    "percivale",
    "bathyplankton",
    "Kinkaider's",
    "bricole",
    "nonreader's",
    "clausular",
    "Pangwe's",
    "deploying",
    "perissodactylous",
    "mazaltov",
    "otoconium",
    "Agee's",
    "Jewling's",
    "Quinter's",
    "prounionism",
    "Jon's",
    "stogeys",
    "cantillates",
    "Mpangwe",
    "fisherfolk",
    "luxation's",
    "confliction",
    "Dioscoreaceae",
    "Glennon's",
    "dereign",
    "officerism",
    "Kenilworth",
    "outstaying",
    "squiggle",
    "Delaplane's",
    "falconoid",
    "polyandrious",
    "stalactites",
    "Kathlyn's",
    "Warners",
    "basined",
    "Deluc",
    "strombiform",
    "Asklepios",
    "provincial's",
    "Atremata",
    "ticktack's",
    "vibratilities",
    "circumhorizontal",
    "overwash's",
    "Freefone's",
    "oversimplifies",
    "dorsipinal",
    "Sharp",
    "hippiehood's",
    "pentode's",
    "quodlibet",
    "misrendered",
    "varella",
    "envelope",
    "Aurungzeb's",
    "proctorship's",
    "inseam's",
    "Wykehamist",
    "deribs",
    "hematophyte",
    "defervescing",
    "Rhinegrave",
    "fainted",
    "schoolboy's",
    "Sihasapa",
    "comeuppance's",
    "pachycephalic",
    "Dorthy's",
    "Squatinidae's",
    "Fawnia's",
    "archaizers",
    "distorter",
    "promoter's",
    "Denair's",
    "riverward",
    "weans",
    "flecking",
    "pharyngopalatinus",
    "rous",
    "Republicanism's",
    "Fars",
    "mailing's",
    "oxytoluene",
    "undivulged",
    "Suberitidae's",
    "lackaday",
    "Jetson's",
    "slyboots's",
    "Arenzville",
    "rest's",
    "brugh's",
    "purveyance",
    "unburly",
    "dislock",
    "houseman",
    "malapportionment's",
    "Tammie's",
    "salmonellosis's",
    "paramitome",
    "desiderata",
    "knuckling",
    "invitatory's",
    "analogous",
    "ochlophobist",
    "hoop",
    "idiotical",
    "entomostracan",
    "Slater",
    "Schifra",
    "gamotropism",
    "oscurrantist",
    "Ermani",
    "pendulously",
    "stickabilities",
    "balkanize",
    "Xenopus",
    "hemichorea",
    "mecca",
    "unmissionized",
    "indowing",
    "dethroning",
    "reburying",
    "Reeve's",
    "Mbandaka's",
    "inoculum",
    "recuses",
    "shagpate",
    "alnagers",
    "nigrosin's",
    "abature",
    "ascogonidia",
    "peletre",
    "stuffing",
    "rouleau's",
    "eyrie",
    "ixodic",
    "thiobacteriaceae",
    "ephydriad",
    "trebles",
    "kinglessness",
    "Caractacus",
    "preslices",
    "kiosks",
    "Queensland",
    "matchup's",
    "isospore",
    "saxitoxin",
    "backboard's",
    "dredge's",
    "Hatcher's",
    "assumptiveness",
    "swastica's",
    "discredit's",
    "Masefield",
    "fiendlier",
    "lacinula",
    "anticlimax",
    "oversized",
    "drusy",
    "octavo's",
    "hydride",
    "decamerous",
    "metalized",
    "histochemists",
    "fruitbearing",
    "Nautiloidea",
    "hypophysectomies",
    "superinscription",
    "eludible",
    "Ionian's",
    "MiG",
    "adorers",
    "fourteenfold",
    "heterokaryons",
    "cestraciont",
    "unpreluded",
    "enceintes",
    "subdenomination",
    "alleluia",
    "distritbuting",
    "Medusaean",
    "Jessieville's",
    "brune",
    "azolitmin",
    "dhyal",
    "speeches",
    "Anastatica",
    "philocalic",
    "paleocortical",
    "Trafalgar",
    "anabaena",
    "tuberculars",
    "motivate",
    "burdened",
    "Khosa",
    "plowshoe",
    "puls",
    "wyvern",
    "cosmetized",
    "polypore's",
    "androgonium",
    "stathenries",
    "Eustasius",
    "Saccobranchus",
    "bc",
    "carbazole's",
    "Teutomania",
    "brominize",
    "morro's",
    "rhynchocoele",
    "predispose",
    "cushewbird",
    "arrayal's",
    "krabs",
    "boxen",
    "Birchist's",
    "nonstructural",
    "subplacentas",
    "glitchy",
    "neoblast's",
    "perceptually",
    "unroped",
    "collusion's",
    "metropathia",
    "devalue",
    "Maxy's",
    "spheroidism",
    "Diels",
    "joual",
    "elect",
    "cycas",
    "mockadoes",
    "entries",
    "syncing",
    "sterlingness's",
    "almuce",
    "sanitaria",
    "suba's",
    "supernecessity",
    "overwound",
    "critism",
    "erythropoietins",
    "potentiator",
    "micromillimeter's",
    "supportability's",
    "hyaloplasmic",
    "Cneorum's",
    "chaining",
    "pedestalling's",
    "Helvidian",
    "antiracist's",
    "peritonaeums",
    "manganous",
    "densate",
    "Bagirmi",
    "counterwoman's",
    "heathery",
    "copalcocote",
    "houhere",
    "Bovidae",
    "Faeroese",
    "entomologic",
    "heniquen's",
    "diapensiaceous",
    "molochs",
    "jomo",
    "politico's",
    "uncourageousness",
    "MariaDB's",
    "distilling",
    "nondancers",
    "recalibrations",
    "eucalyptus",
    "banking's",
    "reicing",
    "forletting",
    "abattoir's",
    "anaphoral",
    "Valdivia's",
    "ellipsoids",
    "cathedrallike",
    "Paulician's",
    "Jhuria",
    "supraterrestrial",
    "gerfalcons",
    "houppelande",
    "laminarin",
    "equivokes",
    "apocynum",
    "symbolographies",
    "mislodged",
    "ophiolite",
    "birt",
    "reinfuses",
    "Maurise's",
    "Elyot",
    "gods",
    "Malplaquet's",
    "pickpocketism",
    "Duplicidentata's",
    "Arsinoitherium's",
    "grooliest",
    "Yurev",
    "bloodthirstiest",
    "Hildagard's",
    "jurisprudentially",
    "puncturers",
    "steroid",
    "blowball",
    "superheterodynes",
    "tainture",
    "Hylobates's",
    "Samau's",
    "dynast",
    "parkour",
    "dourade",
    "bedizenments",
    "extraphysical",
    "oranges",
    "tutted",
    "airbills",
    "Petronille's",
    "Azorean's",
    "chuckrum",
    "boozier",
    "anthropolatries",
    "encratism",
    "docker",
    "possemen",
    "heypen",
    "hanch",
    "latheriest",
    "Enhydrinae",
    "sifting's",
    "coitions",
    "bosporus",
    "setterwort",
    "furiosa",
    "general's",
    "Araneae",
    "soopings",
    "migrant",
    "trepanner",
    "detestablenesses",
    "zinckenite's",
    "yferre",
    "sabermetrician",
    "capos",
    "propend",
    "epilate",
    "Sagaponack",
    "Attidae",
    "Ochrana's",
    "Alectryon",
    "confoundednesses",
    "stubbliest",
    "vaccinator",
    "dissogony",
    "Methodist",
    "irreligiousnesses",
    "intramolecular",
    "Typhon's",
    "Plutonism",
    "discumber",
    "butyrolactone",
    "magazinelet",
    "formalness",
    "somites",
    "emplonged",
    "Hagen's",
    "poem's",
    "warrands",
    "Maely's",
    "aired",
    "accomplish",
    "disintricated",
    "draggletailedness",
    "stoneite",
    "weeble",
    "zoobiotic",
    "sighting",
    "swelchie",
    "preheater's",
    "vestiture",
    "snowfleck",
    "Kidder's",
    "nondebilitative",
    "gallature",
    "kyushu",
    "Meloidae's",
    "fatbirds",
    "antiaphrodisiac",
    "dateableness",
    "vaccination's",
    "Mendenhall",
    "kasher",
    "Aria's",
    "unresounded",
    "preexhaustion",
    "actinouraniums",
    "Wahoo's",
    "satyr's",
    "Unni",
    "Pectinibranchia's",
    "hematozymotic",
    "Epizoa",
    "Loretto's",
    "acheer",
    "exteroceptive",
    "lorries",
    "incitable",
    "copingstones",
    "sorehon",
    "moosa",
    "Hydrometridae's",
    "phacolite",
    "sollars",
    "Cuphea",
    "Chabichou",
    "striature",
    "Bellaghy",
    "gastroduodenoscopy",
    "detonator's",
    "Blodenwedd",
    "discommendations",
    "unfixities",
    "centralistic",
    "Shuma",
    "slowhound",
    "Triarthrus's",
    "noctambulant",
    "expropriable",
    "xanthomas",
    "underwriting",
    "congresswoman",
    "proamendment",
    "desensitization's",
    "totalitizer",
    "Gersham's",
    "chillier",
    "cyprinid's",
    "overcuriousness",
    "dikelocephalid",
    "alehoof",
    "Felecia's",
    "filling",
    "augmentive",
    "ingates",
    "fantasticality",
    "mallow's",
    "nimrod",
    "Tympanuchus's",
    "innovative",
    "fibster's",
    "detoured",
    "caltrop",
    "rehash",
    "strawless's",
    "bratchet's",
    "douches",
    "underbite",
    "gangsterism",
    "Benzedrine",
    "chambranle's",
    "huntaway",
    "chandrakanta",
    "selamlik's",
    "Sperling's",
    "inflictions",
    "Kline",
    "protanomal",
    "foretime",
    "Rickman's",
    "quoitlike",
    "acidheads",
    "unplough",
    "pleuropneumonic",
    "logouts",
    "squatters",
    "engrege",
    "tetraglottic",
    "Toltecs",
    "cressy",
    "hydrocrack",
    "Wyethia's",
    "scribacious",
    "fingerhole",
    "antennas",
    "Aplodontia's",
    "time's",
    "Socratist's",
    "Germanizing",
    "abbasid",
    "ritualistically",
    "Cedarville's",
    "Iberes's",
    "shorls",
    "muckers",
    "Monsarrat",
    "MGeolE's",
    "tsesarewiches",
    "monoeciousness",
    "longspur",
    "potamophilous",
    "antirape",
    "pseudotuberculosis's",
    "Cruft",
    "haikun",
    "alambique",
    "una",
    "uglis",
    "Scottice's",
    "Rotal",
    "ninhydrin",
    "renationalize",
    "yeasayers",
    "unfolder's",
    "cairn's",
    "unspellable",
    "cymbalos",
    "Fittonia",
    "pathophysiologies",
    "snapps",
    "dipleurule",
    "perfidious",
    "soldierdom",
    "suspensory's",
    "rusticities",
    "conjunctivenesses",
    "glissader",
    "semialcoholic",
    "Paddy",
    "oppugner's",
    "Chaco",
    "Batesville's",
    "preferential",
    "brome's",
    "Seconal's",
    "Memling",
    "sternoscapular",
    "venenose",
    "postencephalon",
    "Brachyurus",
    "strumming",
    "attagen",
    "blabbermouth's",
    "mucorales",
    "affections",
    "nephroparalysis",
    "unreverential",
    "bowmaker",
    "Collie's",
    "geophilus",
    "unvoluptuous",
    "Mauri",
    "storming",
    "unluckful",
    "solstitially",
    "beni",
    "wippen's",
    "incumbition",
    "vulpicidism",
    "incisiform",
    "hyperin",
    "dysacousia",
    "motiest",
    "syr",
    "tawsy",
    "Henleigh's",
    "gallinaceon's",
    "perennibranch",
    "longness's",
    "ataxiameter",
    "displodes",
    "igniferousness",
    "misbelieves",
    "Sybarite's",
    "kilnman",
    "renewednesses",
    "egards",
    "magdalene",
    "Gygaea's",
    "telerecord",
    "padle",
    "Preminger's",
    "conspue",
    "undershored",
    "nones",
    "octodecimo's",
    "subastral",
    "Fremantle",
    "recoagulate",
    "excussion",
    "minuscule's",
    "hicket",
    "pseudoaesthetic",
    "thermatologic",
    "Acanthophis",
    "surds",
    "optimalisation's",
    "serratirostral",
    "nepotism"
}; const unsigned int words_end = __LINE__;

const unsigned int word_count = words_end - words_start - 1;

/* da tam vsechny ty klice */
void insert_bunch(ht_table_t *table) {
    float *current;
    for (unsigned int i = 0; i < word_count; i++) {

        /* vlozi prvek */
        ht_insert(table, words[i], 0.0);

        /* ujisti se ze prvek tam je */
        assert(ht_search(table, words[i]));

        /* ujisti se ze ten prvek ktery tam je ma spravnou hodnotu */
        current = ht_get(table, words[i]);
        assert(current != NULL);
        assert(*current == 0.0); /* == u floutu je legalni protoze se nad tou 
        hodnotou nekonaly zadne aritmeticke operace */
    }
}

/* updatne hodnoty klicu */
void set_values(ht_table_t *table) {
    for (unsigned int i = 0; i < word_count; i++) {
        ht_insert(table, words[i], (float)(strlen(words[i])));
    }
}

/* vypise vsechny klice a ujisti se ze jsou tam dobry hodnoty */
void print_all(ht_table_t *table) {
    float *current = NULL;
    for (unsigned int i = 0; i < word_count; i++) {
        current = ht_get(table, words[i]);

        /* ujisti se ze ten klic tam opravdu je */
        assert(current != NULL);

        /* vypise klic a jeho hodnotu */
        #if verbose
        printf("%s: %.2f\n", words[i], (double)(*current));
        #endif // #if verbose

        /* zkontroluje jestli je hodnota klice takova jaka ma byt */
        assert(*current == (float)strlen(words[i]));
    }

}

/* smaze ctvrtinu klicu individualne */
void delete_quarter(ht_table_t *table) {
    unsigned int quarter = word_count / 4;
    for (unsigned int i = quarter; i < 2 * quarter; i++) {

        #if verbose
        printf("mazu %s individualne\n", words[i]);
        #endif // #if verbose

        /* smaze prvek */
        ht_delete(table, words[i]);

        /* podiva se ze tam fakt neni */
        assert(ht_search(table, words[i]) == NULL);
        assert(ht_get(table, words[i]) == NULL);
    }
}

/* ujisti se ze v tabulce nic neni */
void assert_empty(ht_table_t *table) {
    for (unsigned int i = 0; i < MAX_HT_SIZE; i++) {
        assert((*table)[i] == NULL);
    }
}

void test_1() {

    /* inicializuje tabulku */
    ht_table_t table_arr;
    ht_table_t *table = &table_arr;
    ht_init(table);

    /* zkontroluje ze v inicializovane tabulce neni smeti */
    assert_empty(table);

    /* zanda tam polozky */
    insert_bunch(table);
    set_values(table);

    /* vypise polozky a zkontroluje veci */
    print_all(table);


    /* smaze nektere polozky individualne */
    delete_quarter(table);

    /* smaze vsechno takze kontroluj pres valgrind*/
    ht_delete_all(table);

    /* ujisti se ze v tabulce nic neni 
    (pozor to nedetekuje leaky stejne to pust pres valgrind) */
    assert_empty(table);

}

/* smaze kazdou druhou polozku a ujisti se taky ze ten zbytek tam zustal */
void delete_even(ht_table_t *table) {

    for (unsigned int i = 0; i < word_count; i += 2) {
        ht_delete(table, words[i]);
    }
    for (unsigned int i = 0; i < word_count; i += 2) {
        assert(ht_search(table, words[i]) == NULL);
    }
    for (unsigned int i = 1; i < word_count; i += 2) {
        assert(ht_search(table, words[i]) != NULL);
    }

}

void insert_bunch_many_times(ht_table_t *table) {
    for (unsigned int i = 0; i < 50; i++) {
        insert_bunch(table);
    }
}

void test_2() {

    /* inicializuje tabulku */
    ht_table_t table_arr;
    ht_table_t *table = &table_arr;
    ht_init(table);

    insert_bunch(table);
    delete_even(table);
    ht_delete_all(table);
}
void test_3() {

    /* inicializuje tabulku */
    ht_table_t table_arr;
    ht_table_t *table = &table_arr;
    ht_init(table);

    insert_bunch_many_times(table);

    delete_even(table);
    delete_quarter(table);
    ht_delete_all(table);

}

/* spusti testy nekolikrat v ruznem poradi */
void all_tests() {
    test_1();
    test_2();
    test_3();

    test_1();
    test_3();
    test_2();

    test_3();
    test_2();
    test_1();

    test_2();
    test_1();
    test_3();

    test_2();
    test_3();
    test_1();
}

int main() {

    unsigned int n = 100;
    for (unsigned int i = 0; i < n; i++){
        printf("%d/%d\n", i + 1, n);
        all_tests();
    }

    printf("👍👍👍 dobry 😊 vsechny testy prosly 🥰 nyni to pust pres "
    "valgrind 🔥💯\n");

    /* odkomentovat jestli se chces ujistit ze funguje assert */
    // assert(0);

    return 0;
}
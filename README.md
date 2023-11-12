# testy pro hashtable

# upozorneni 2
pan Zavrel psal na moodle forum ze funkci `get_hash` NEMATE MENIT (i kdyz je na picu)

# upozorneni
pokud vam bude segfaultovat program, je mozny ze to zpusobuje funkce `get_hash`
ta pro nektere utf-8 retezce vraci ZAPORNY hash 🙂 opraveni funkce `get_hash`
je tak trosku zasah do kostry, takze necham na vas, jestli s tim budete neco
delat nebo ne. pan Zavrel o teto skutecnosti vi a nechal se slyset ze zadani
je v poradku protoze je v komentari nad funkci `get_hash` napsano:
```c
/* zamyslete se nad kvalitou funkce */
```

## pouziti testu pro hashtable
- do adresare `hashtable` pridas `test_muj.c` a `test_muj_2.c`
- obsah puvodniho `Makefile` nahradis obsahem meho `Makefile`
- `make test_muj`
- `./test_muj < /usr/share/dict/american-english-insane` (trva tak 5 min nez to dobehne a pres valgrind jeste dyl)
  - pokud nemas tak `/usr/share/dict/words` nebo
  - `sudo apt install wamerican-insane` (pro debian)
- `make test_muj_2` - prelozi test i ho spusti - je to hromada assertu

potom spuste testy jeste pres valgrind

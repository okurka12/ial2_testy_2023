# testy pro hashtable
## pouziti testu pro hashtable
- do adresare `hashtable` pridas `test_muj.c` a `test_muj_2.c`
- obsah puvodniho `Makefile` nahradis obsahem meho `Makefile`
- `make test_muj`
- `./test_muj < /usr/share/dict/american-english-insane` (trva tak 5 min nez to dobehne a pres valgrind jeste dyl)
  - pokud nemas tak `/usr/share/dict/words` nebo
  - `sudo apt install wamerican-insane` (pro debian)
- `make test_muj_2` - prelozi test i ho spusti - je to hromada assertu

potom spuste testy jeste pres valgrind
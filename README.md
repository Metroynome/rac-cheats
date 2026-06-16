# gc-cheats

Sample project showing how to use libdl to create cheat codes for Ratchet and Clank: Up Your Arsenal
## Build with docker
### Clone Repos
```sh
git clone https://github.com/Metroynome/gc-cheats.git
```
### Get PS2SDK via Docker
You will need to run this command in the top directory that `horizon-uya-patch` and `uya-cheats` is in.  `uya-cheats` requires access to both directories.
```sh
docker pull ps2dev/ps2dev:v1.2.0
docker run -it --rm -v "$PWD\:/src" ps2dev/ps2dev:v1.2.0
cd src
```

### Install libgc
```sh
./docker-init.sh
```

## Create the cheat!
To create the cheats, just cd into a directory and then run `make clean && make`
Example:
```sh
cd ./test/
make clean && make
```
The output file will be placed into the /bin/ directory.


Make it:
```sh
make clean && make
```

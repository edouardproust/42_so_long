# so_long (42 School Project)

`so_long` is a 2D game where a character collects items in a map, then reaches an exit point.

## Install

1. Install dependancies for Ubuntu: 
```
sudo apt update
sudo apt install cmake build-essential libx11-dev libglfw3-dev libglfw3 xorg-dev
```

2. Build game
```
git clone https://github.com/edouardproust/42_so_long.git so_long
cd so_long
make
```

3. Play
```
./so_long <map_filepath>
```
Replace `map_filepath` by any map path located in `test/map/` folder. Example:
```
./so_long test/map/5.suspicious_meadow.ber
```

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

## Play
```
./so_long <map_filepath>
```
Replace `map_filepath` by the path of any map located in the `test/maps/` folder. Example:
```
./so_long test/maps/0.prologue.ber
```

## Leaks

Valgrind test is returning a summury containing "still reachable" blocks:
```
==14110== LEAK SUMMARY:
==14110==    definitely lost: 0 bytes in 0 blocks
==14110==    indirectly lost: 0 bytes in 0 blocks
==14110==      possibly lost: 0 bytes in 0 blocks
==14110==    still reachable: 309,526 bytes in 3,127 blocks
==14110==         suppressed: 0 bytes in 0 blocks
```
This is the only fact of the library dependencies (see [Github issue #130](https://github.com/codam-coding-college/MLX42/issues/130) and is nothing related with my program.

To prove that, i made the most minimalistic program using MLX42 library (simply opening and closing a window). You can run it using `cd test/lib_leaks_proof && make`. You will see that the valgrind summury is exactly the same as the one above.

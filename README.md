# so_long (42 School Project)

**The County of Pognon Land has been destroyed by the hordes of foul, stinking goblins. Sir Pognon, returning from his campaign, is devastated to see his county in such a state. Recover the sacks of Pognon and rebuild your county to repel the wicked goblins.**

- **Subject:** [English](./subject/en.subject.pdf) / [French](./subject/fr.subject.pdf) / [Spanish](./subject/es.subject.pdf)
- **Location:** 42 School Barcelona
- **Validation:** December 2024

![42 push_swap debug output bottom](test/screenshot/42_push_swap__debug__output_2.png)

The `so_long` project is a 2D game where a character collects items in a map, then reaches an exit point.

## Install

1. Install dependancies for Ubuntu: 
```
sudo apt update
sudo apt install cmake build-essential libx11-dev libglfw3-dev libglfw3 xorg-dev
```

2. Build game

I recommand playing the bonus version of the game, as it is more complete (animations, etc). Here is how to build it:
```
git clone https://github.com/edouardproust/42_so_long.git so_long
cd so_long
make bonus
```

## Play

Same thing, here is how to play the bonus version of the game:
```
./so_long_bonus bonus/maps/<map_name>.ber
```
Replace `map_name` by the name of a map located inside the folder `bonus/maps/`. Example:
```
./so_long_bonus bonus/maps/0.prologue.ber
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

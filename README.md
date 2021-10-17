# so_long - 42 School Project

## About

As a graphic design project, so long will enable you to improve your skills in these areas: windows, colors, events, textures, etc.

The program will create a game inside a window corresponding to the map that you use as input.

| Program name | so_long |
| :--- | :--- |
| Arguments | a map in format *.ber |
| External functions | open, close, read, write, printf, malloc, free, perror, strerror, exit, all functions of the MinilibX |
| Libft authorized | Yes |
| Description | You must create a small 2D game where any hero escapes the place after collecting all the collectables |

Example of a valid map (formatted as *.ber):

```
1111111111111  
10010000000C1  
1000011111001  
1P0011E000001  
1111111111111
```

| Symbol | Meaning |
| :--- | :--- |
| 1 | Wall |
| 0 | Floor |
| C | Collectable |
| P | Player |
| E | Exit |

* The map must be closed/surrounded by walls, if not the program must return an error.  
* Map must have at least one exit, one collectible, and one starting position.  
* You don’t need to check if there’s a valid path in the map.  
* The map must be rectangular.

## How to use


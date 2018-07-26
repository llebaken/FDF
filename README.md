# FDF
First Graphics Project

1. Allocate memory for 3 2D arrays
2. Read textfile into 1st 2D Array
3. Calculate coordinates and and add them to the 2nd 2D Array
    - Formula:
      Fx = ((x * scale) - (y * scale))
      Fy = ((x * scale) + (y * scale) /2 + height)
      Coordinate = Fx + Fy
4. Add each Fx into 3rd 2D array
5. Use DDA to draw.

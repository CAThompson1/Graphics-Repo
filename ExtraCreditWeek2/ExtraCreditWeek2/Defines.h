#pragma once
#define RASTER_WIDTH 500
#define RASTER_HEIGHT 500
#define NUM_PIXELS (RASTER_WIDTH * RASTER_HEIGHT)
unsigned SCREEN_ARRAY[NUM_PIXELS];
const char* _studentName = "CaedanThompson";
struct Float2
{
    union
    {
        struct
        {
            float UV[2];
        };
        struct
        {
            float x;
            float y;
        };
    };
};
struct Float4
{
    union
    {
        struct
        {
            float V[4];
        };
        struct
        {
            float x;
            float y;
            float z;
            float w;
        };
    };
};
struct Vertex
{
    Float4 Position;
    Float2 UV;  // added later, would need to define Float2;
    unsigned int Color;
};
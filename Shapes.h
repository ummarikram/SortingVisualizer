#pragma once

// To store coordinates
struct Point
{
    float x, y;
    int length;

    Point()
    {
        x = 0.0f; y = 0.0f; length = 0;
    }

    void SetLength(int length)
    {
        this->length = length;
    }

    void Add(float X, float Y)
    {
        x = X; y = Y;
    }

    bool operator==(const Point& o) const {
        return x == o.x && y == o.y;
    }

    bool operator<(const Point& o)  const {
        return x < o.x || (x == o.x && y < o.y);
    }
};

// To store a shape of 4 vertices e.g square
struct Quad
{
    float X, X1, Y, Y1;

    Quad()
    {
        X = 0; X1 = 0; Y = 0; Y1 = 0;
    }

    Quad(float x, float x1, float y, float y1)
    {
        X = x; X1 = x1; Y = y; Y1 = y1;
    }

    bool operator==(const Quad& o) const {
        return X == o.X && X1 == o.X1 && Y == o.Y && Y1 == o.Y1;
    }

    bool operator<(const Quad& o)  const {
        return X < o.X || (X == o.X && Y < o.Y);
    }
};

// To represent each bar of array.
struct Node
{
    int Value;  // its value
    int Range;  // Range of values
    const int Max = 60; // Max value
    const int Min = 1; // Min value
    Point Position;  // Position 

    Node()
    {
        Range = Max - Min + 1;
        Value = rand() % Range + Min;  // Random value for every bar
        Position.x = 0; Position.y = 0;
    }

};
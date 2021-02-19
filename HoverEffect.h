#pragma once

// For hover animation played on Text
void CheckHover(Shader& shader, const int& HoverBlock, const bool& isHovering)
{
    float ScaleFactor = float(Screen_Width) / float(1280);
    Point BubbleSortScaleFactor(   Screen_Width * 0.12, Screen_Height * 0.80);
    Point SelectionSortScaleFactor(Screen_Width * 0.42, Screen_Height * 0.80);
    Point InsertionSortScaleFactor(Screen_Width * 0.74, Screen_Height * 0.80);
    Point QuickSortScaleFactor(    Screen_Width * 0.27, Screen_Height * 0.56);
    Point MergeSortScaleFactor(    Screen_Width * 0.61, Screen_Height * 0.56);
    Point CocktailSortScaleFactor( Screen_Width * 0.42, Screen_Height * 0.32);

    RenderText(shader, "CHOOSE SORTING ALGORITHM !", Screen_Width * 0.34, Screen_Height * 0.93, ScaleFactor, glm::vec3(0.5f, 0.3f, 0.7f));

    // if hovered on first block which is of bubble sort
    if (!isHovering && HoverBlock == 0)
    {
        // Display Bubble Sort as Red
        RenderText(shader, "BUBBLE SORT", BubbleSortScaleFactor.x, BubbleSortScaleFactor.y, ScaleFactor, glm::vec3(1.0f, 0.0f, 0.0f));
        RenderText(shader, "SELECTION SORT", SelectionSortScaleFactor.x, SelectionSortScaleFactor.y, ScaleFactor, glm::vec3(0.0f, 0.0f, 0.0f));
        RenderText(shader, "INSERTION SORT", InsertionSortScaleFactor.x, InsertionSortScaleFactor.y, ScaleFactor, glm::vec3(0.0f, 0.0f, 0.0f));
        RenderText(shader, "QUICK SORT", QuickSortScaleFactor.x, QuickSortScaleFactor.y, ScaleFactor, glm::vec3(0.0f, 0.0f, 0.0f));
        RenderText(shader, "MERGE SORT", MergeSortScaleFactor.x, MergeSortScaleFactor.y, ScaleFactor, glm::vec3(0.0f, 0.0f, 0.0f));
        RenderText(shader, "COCKTAIL SORT", CocktailSortScaleFactor.x, CocktailSortScaleFactor.y, ScaleFactor, glm::vec3(0.0f, 0.0f, 0.0f));
    }

    // Same check for other blocks
    else if (!isHovering && HoverBlock == 1)
    {
        RenderText(shader, "BUBBLE SORT", BubbleSortScaleFactor.x, BubbleSortScaleFactor.y, ScaleFactor, glm::vec3(0.0f, 0.0f, 0.0f));
        RenderText(shader, "SELECTION SORT", SelectionSortScaleFactor.x, SelectionSortScaleFactor.y, ScaleFactor, glm::vec3(1.0f, 0.0f, 0.0f));
        RenderText(shader, "INSERTION SORT", InsertionSortScaleFactor.x, InsertionSortScaleFactor.y, ScaleFactor, glm::vec3(0.0f, 0.0f, 0.0f));
        RenderText(shader, "QUICK SORT", QuickSortScaleFactor.x, QuickSortScaleFactor.y, ScaleFactor, glm::vec3(0.0f, 0.0f, 0.0f));
        RenderText(shader, "MERGE SORT", MergeSortScaleFactor.x, MergeSortScaleFactor.y, ScaleFactor, glm::vec3(0.0f, 0.0f, 0.0f));
        RenderText(shader, "COCKTAIL SORT", CocktailSortScaleFactor.x, CocktailSortScaleFactor.y, ScaleFactor, glm::vec3(0.0f, 0.0f, 0.0f));
    }

    else if (!isHovering && HoverBlock == 2)
    {
        RenderText(shader, "BUBBLE SORT", BubbleSortScaleFactor.x, BubbleSortScaleFactor.y, ScaleFactor, glm::vec3(0.0f, 0.0f, 0.0f));
        RenderText(shader, "SELECTION SORT", SelectionSortScaleFactor.x, SelectionSortScaleFactor.y, ScaleFactor, glm::vec3(0.0f, 0.0f, 0.0f));
        RenderText(shader, "INSERTION SORT", InsertionSortScaleFactor.x, InsertionSortScaleFactor.y, ScaleFactor, glm::vec3(1.0f, 0.0f, 0.0f));
        RenderText(shader, "QUICK SORT", QuickSortScaleFactor.x, QuickSortScaleFactor.y, ScaleFactor, glm::vec3(0.0f, 0.0f, 0.0f));
        RenderText(shader, "MERGE SORT", MergeSortScaleFactor.x, MergeSortScaleFactor.y, ScaleFactor, glm::vec3(0.0f, 0.0f, 0.0f));
        RenderText(shader, "COCKTAIL SORT", CocktailSortScaleFactor.x, CocktailSortScaleFactor.y, ScaleFactor, glm::vec3(0.0f, 0.0f, 0.0f));
    }

    else if (!isHovering && HoverBlock == 3)
    {
        RenderText(shader, "BUBBLE SORT", BubbleSortScaleFactor.x, BubbleSortScaleFactor.y, ScaleFactor, glm::vec3(0.0f, 0.0f, 0.0f));
        RenderText(shader, "SELECTION SORT", SelectionSortScaleFactor.x, SelectionSortScaleFactor.y, ScaleFactor, glm::vec3(0.0f, 0.0f, 0.0f));
        RenderText(shader, "INSERTION SORT", InsertionSortScaleFactor.x, InsertionSortScaleFactor.y, ScaleFactor, glm::vec3(0.0f, 0.0f, 0.0f));
        RenderText(shader, "QUICK SORT", QuickSortScaleFactor.x, QuickSortScaleFactor.y, ScaleFactor, glm::vec3(1.0f, 0.0f, 0.0f));
        RenderText(shader, "MERGE SORT", MergeSortScaleFactor.x, MergeSortScaleFactor.y, ScaleFactor, glm::vec3(0.0f, 0.0f, 0.0f));
        RenderText(shader, "COCKTAIL SORT", CocktailSortScaleFactor.x, CocktailSortScaleFactor.y, ScaleFactor, glm::vec3(0.0f, 0.0f, 0.0f));
    }

    else if (!isHovering && HoverBlock == 4)
    {
        RenderText(shader, "BUBBLE SORT", BubbleSortScaleFactor.x, BubbleSortScaleFactor.y, ScaleFactor, glm::vec3(0.0f, 0.0f, 0.0f));
        RenderText(shader, "SELECTION SORT", SelectionSortScaleFactor.x, SelectionSortScaleFactor.y, ScaleFactor, glm::vec3(0.0f, 0.0f, 0.0f));
        RenderText(shader, "INSERTION SORT", InsertionSortScaleFactor.x, InsertionSortScaleFactor.y, ScaleFactor, glm::vec3(0.0f, 0.0f, 0.0f));
        RenderText(shader, "QUICK SORT", QuickSortScaleFactor.x, QuickSortScaleFactor.y, ScaleFactor, glm::vec3(0.0f, 0.0f, 0.0f));
        RenderText(shader, "MERGE SORT", MergeSortScaleFactor.x, MergeSortScaleFactor.y, ScaleFactor, glm::vec3(1.0f, 0.0f, 0.0f));
        RenderText(shader, "COCKTAIL SORT", CocktailSortScaleFactor.x, CocktailSortScaleFactor.y, ScaleFactor, glm::vec3(0.0f, 0.0f, 0.0f));
    }

    else if (!isHovering && HoverBlock == 5)
    {
        RenderText(shader, "BUBBLE SORT", BubbleSortScaleFactor.x, BubbleSortScaleFactor.y, ScaleFactor, glm::vec3(0.0f, 0.0f, 0.0f));
        RenderText(shader, "SELECTION SORT", SelectionSortScaleFactor.x, SelectionSortScaleFactor.y, ScaleFactor, glm::vec3(0.0f, 0.0f, 0.0f));
        RenderText(shader, "INSERTION SORT", InsertionSortScaleFactor.x, InsertionSortScaleFactor.y, ScaleFactor, glm::vec3(0.0f, 0.0f, 0.0f));
        RenderText(shader, "QUICK SORT", QuickSortScaleFactor.x, QuickSortScaleFactor.y, ScaleFactor, glm::vec3(0.0f, 0.0f, 0.0f));
        RenderText(shader, "MERGE SORT", MergeSortScaleFactor.x, MergeSortScaleFactor.y, ScaleFactor, glm::vec3(0.0f, 0.0f, 0.0f));
        RenderText(shader, "COCKTAIL SORT", CocktailSortScaleFactor.x, CocktailSortScaleFactor.y, ScaleFactor, glm::vec3(1.0f, 0.0f, 0.0f));
    }

    // if no hovering
    else
    {
        RenderText(shader, "BUBBLE SORT", BubbleSortScaleFactor.x, BubbleSortScaleFactor.y, ScaleFactor, glm::vec3(0.0f, 0.0f, 0.0f));
        RenderText(shader, "SELECTION SORT", SelectionSortScaleFactor.x, SelectionSortScaleFactor.y, ScaleFactor, glm::vec3(0.0f, 0.0f, 0.0f));
        RenderText(shader, "INSERTION SORT", InsertionSortScaleFactor.x, InsertionSortScaleFactor.y, ScaleFactor, glm::vec3(0.0f, 0.0f, 0.0f));
        RenderText(shader, "QUICK SORT", QuickSortScaleFactor.x, QuickSortScaleFactor.y, ScaleFactor, glm::vec3(0.0f, 0.0f, 0.0f));
        RenderText(shader, "MERGE SORT", MergeSortScaleFactor.x, MergeSortScaleFactor.y, ScaleFactor, glm::vec3(0.0f, 0.0f, 0.0f));
        RenderText(shader, "COCKTAIL SORT", CocktailSortScaleFactor.x, CocktailSortScaleFactor.y, ScaleFactor, glm::vec3(0.0f, 0.0f, 0.0f));
    }
}
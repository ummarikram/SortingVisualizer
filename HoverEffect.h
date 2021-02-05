#pragma once

// For hover animation played on Text
void CheckHover(Shader& shader, const int& HoverBlock, const bool& isHovering)
{
    RenderText(shader, "CHOOSE SORTING ALGORITHM !", 450.0f, 670.0f, 1.0f, glm::vec3(0.5f, 0.3f, 0.7f));

    // if hovered on first block which is of bubble sort
    if (!isHovering && HoverBlock == 0)
    {
        // Display Bubble Sort as Red
        RenderText(shader, "BUBBLE SORT", 150.0f, 570.0f, 1.0f, glm::vec3(1.0f, 0.0f, 0.0f));
        RenderText(shader, "SELECTION SORT", 540.0f, 570.0f, 1.0f, glm::vec3(0.0f, 0.0f, 0.0f));
        RenderText(shader, "INSERTION SORT", 950.0f, 570.0f, 1.0f, glm::vec3(0.0f, 0.0f, 0.0f));
        RenderText(shader, "QUICK SORT", 350.0f, 400.0f, 1.0f, glm::vec3(0.0f, 0.0f, 0.0f));
        RenderText(shader, "MERGE SORT", 780.0f, 400.0f, 1.0f, glm::vec3(0.0f, 0.0f, 0.0f));
        RenderText(shader, "COCKTAIL SORT", 540.0f, 230.0f, 1.0f, glm::vec3(0.0f, 0.0f, 0.0f));
    }

    // Same check for other blocks
    else if (!isHovering && HoverBlock == 1)
    {
        RenderText(shader, "BUBBLE SORT", 150.0f, 570.0f, 1.0f, glm::vec3(0.0f, 0.0f, 0.0f));
        RenderText(shader, "SELECTION SORT", 540.0f, 570.0f, 1.0f, glm::vec3(1.0f, 0.0f, 0.0f));
        RenderText(shader, "INSERTION SORT", 950.0f, 570.0f, 1.0f, glm::vec3(0.0f, 0.0f, 0.0f));
        RenderText(shader, "QUICK SORT", 350.0f, 400.0f, 1.0f, glm::vec3(0.0f, 0.0f, 0.0f));
        RenderText(shader, "MERGE SORT", 780.0f, 400.0f, 1.0f, glm::vec3(0.0f, 0.0f, 0.0f));
        RenderText(shader, "COCKTAIL SORT", 540.0f, 230.0f, 1.0f, glm::vec3(0.0f, 0.0f, 0.0f));
    }

    else if (!isHovering && HoverBlock == 2)
    {
        RenderText(shader, "BUBBLE SORT", 150.0f, 570.0f, 1.0f, glm::vec3(0.0f, 0.0f, 0.0f));
        RenderText(shader, "SELECTION SORT", 540.0f, 570.0f, 1.0f, glm::vec3(0.0f, 0.0f, 0.0f));
        RenderText(shader, "INSERTION SORT", 950.0f, 570.0f, 1.0f, glm::vec3(1.0f, 0.0f, 0.0f));
        RenderText(shader, "QUICK SORT", 350.0f, 400.0f, 1.0f, glm::vec3(0.0f, 0.0f, 0.0f));
        RenderText(shader, "MERGE SORT", 780.0f, 400.0f, 1.0f, glm::vec3(0.0f, 0.0f, 0.0f));
        RenderText(shader, "COCKTAIL SORT", 540.0f, 230.0f, 1.0f, glm::vec3(0.0f, 0.0f, 0.0f));
    }

    else if (!isHovering && HoverBlock == 3)
    {
        RenderText(shader, "BUBBLE SORT", 150.0f, 570.0f, 1.0f, glm::vec3(0.0f, 0.0f, 0.0f));
        RenderText(shader, "SELECTION SORT", 540.0f, 570.0f, 1.0f, glm::vec3(0.0f, 0.0f, 0.0f));
        RenderText(shader, "INSERTION SORT", 950.0f, 570.0f, 1.0f, glm::vec3(0.0f, 0.0f, 0.0f));
        RenderText(shader, "QUICK SORT", 350.0f, 400.0f, 1.0f, glm::vec3(1.0f, 0.0f, 0.0f));
        RenderText(shader, "MERGE SORT", 780.0f, 400.0f, 1.0f, glm::vec3(0.0f, 0.0f, 0.0f));
        RenderText(shader, "COCKTAIL SORT", 540.0f, 230.0f, 1.0f, glm::vec3(0.0f, 0.0f, 0.0f));
    }

    else if (!isHovering && HoverBlock == 4)
    {
        RenderText(shader, "BUBBLE SORT", 150.0f, 570.0f, 1.0f, glm::vec3(0.0f, 0.0f, 0.0f));
        RenderText(shader, "SELECTION SORT", 540.0f, 570.0f, 1.0f, glm::vec3(0.0f, 0.0f, 0.0f));
        RenderText(shader, "INSERTION SORT", 950.0f, 570.0f, 1.0f, glm::vec3(0.0f, 0.0f, 0.0f));
        RenderText(shader, "QUICK SORT", 350.0f, 400.0f, 1.0f, glm::vec3(0.0f, 0.0f, 0.0f));
        RenderText(shader, "MERGE SORT", 780.0f, 400.0f, 1.0f, glm::vec3(1.0f, 0.0f, 0.0f));
        RenderText(shader, "COCKTAIL SORT", 540.0f, 230.0f, 1.0f, glm::vec3(0.0f, 0.0f, 0.0f));
    }

    else if (!isHovering && HoverBlock == 5)
    {
        RenderText(shader, "BUBBLE SORT", 150.0f, 570.0f, 1.0f, glm::vec3(0.0f, 0.0f, 0.0f));
        RenderText(shader, "SELECTION SORT", 540.0f, 570.0f, 1.0f, glm::vec3(0.0f, 0.0f, 0.0f));
        RenderText(shader, "INSERTION SORT", 950.0f, 570.0f, 1.0f, glm::vec3(0.0f, 0.0f, 0.0f));
        RenderText(shader, "QUICK SORT", 350.0f, 400.0f, 1.0f, glm::vec3(0.0f, 0.0f, 0.0f));
        RenderText(shader, "MERGE SORT", 780.0f, 400.0f, 1.0f, glm::vec3(0.0f, 0.0f, 0.0f));
        RenderText(shader, "COCKTAIL SORT", 540.0f, 230.0f, 1.0f, glm::vec3(1.0f, 0.0f, 0.0f));
    }

    // if no hovering
    else
    {
        RenderText(shader, "BUBBLE SORT", 150.0f, 570.0f, 1.0f, glm::vec3(0.0f, 0.0f, 0.0f));
        RenderText(shader, "SELECTION SORT", 540.0f, 570.0f, 1.0f, glm::vec3(0.0f, 0.0f, 0.0f));
        RenderText(shader, "INSERTION SORT", 950.0f, 570.0f, 1.0f, glm::vec3(0.0f, 0.0f, 0.0f));
        RenderText(shader, "QUICK SORT", 350.0f, 400.0f, 1.0f, glm::vec3(0.0f, 0.0f, 0.0f));
        RenderText(shader, "MERGE SORT", 780.0f, 400.0f, 1.0f, glm::vec3(0.0f, 0.0f, 0.0f));
        RenderText(shader, "COCKTAIL SORT", 540.0f, 230.0f, 1.0f, glm::vec3(0.0f, 0.0f, 0.0f));
    }
}
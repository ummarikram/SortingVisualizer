#pragma once

// Sorts arrar a[0..n-1] using Cocktail sort 
void Visualizer::CocktailSortNodes()
{
    bool swapped = true;
    static int start = 0;
    static int end = NodeCount - 1;

    while (swapped) {
        // reset the swapped flag on entering 
        // the loop, because it might be true from 
        // a previous iteration. 
        swapped = false;

        // loop from left to right same as 
        // the bubble sort 
        for (int i = start; i < end; ++i)
        {
            if (Nodes[i].Value > Nodes[i + 1].Value)
            {
                Swap(Nodes[i], Nodes[i + 1]);
                swapped = true;
            }
        }

        // if nothing moved, then array is sorted. 
        if (!swapped)
            break;

        // otherwise, reset the swapped flag so that it 
        // can be used in the next stage 
        swapped = false;

        // move the end point back by one, because 
        // item at the end is in its rightful spot 
        --end;

        // from right to left, doing the 
        // same comparison as in the previous stage 
        for (int i = end - 1; i >= start; --i)
        {
            if (Nodes[i].Value > Nodes[i + 1].Value)
            {
                Swap(Nodes[i], Nodes[i + 1]);
                swapped = true;
            }
        }

        // increase the starting point, because 
        // the last stage would have moved the next 
        // smallest number to its rightful spot. 
        ++start;

        break;
    }
}

void Visualizer::DrawCocktailSort()
{
    bool swapped = true;
    static int start = 0;
    static int end = NodeCount - 1;

    while (swapped) {
        // reset the swapped flag on entering 
        // the loop, because it might be true from 
        // a previous iteration. 
        swapped = false;

        // loop from left to right same as 
        // the bubble sort 
        for (int i = start; i < end; ++i)
        {
            if (Nodes[i].Value > Nodes[i + 1].Value)
            {
                DrawColorNodes(i, 1, 0, 0);

                DrawColorNodes(i + 1, 1, 0, 0);

            }

            else
            {
                DrawColorNodes(i, 0, 1, 0);

                DrawColorNodes(i + 1, 0, 1, 0);
            }
        }

        // if nothing moved, then array is sorted. 
        if (!swapped)
            break;

        // otherwise, reset the swapped flag so that it 
        // can be used in the next stage 
        swapped = false;

        // move the end point back by one, because 
        // item at the end is in its rightful spot 
        --end;

        // from right to left, doing the 
        // same comparison as in the previous stage 
        for (int i = end - 1; i >= start; --i)
        {
            if (Nodes[i].Value > Nodes[i + 1].Value)
            {
                DrawColorNodes(i, 1, 0, 0);

                DrawColorNodes(i + 1, 1, 0, 0);

                swapped = true;
            }

            else
            {
                DrawColorNodes(i, 0, 1, 0);

                DrawColorNodes(i + 1, 0, 1, 0);
            }
        }

        // increase the starting point, because 
        // the last stage would have moved the next 
        // smallest number to its rightful spot. 
        ++start;

        break;
    }
}

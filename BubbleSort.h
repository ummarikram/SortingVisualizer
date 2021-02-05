#pragma once

void Visualizer::BubbleSortNodes()
{
    for (int i = 0; i < NodeCount; i++)
    {
        bool StepDone = false;

        for (int j = 0; j < NodeCount - i - 1; j++)
        {
            if (Nodes[j].Value > Nodes[j + 1].Value)
            {
                Swap(Nodes[j], Nodes[j + 1]);

                StepDone = true;

            }

        }

        if (StepDone)
        {
            break;
        }
    }
}

void Visualizer::DrawBubbleSort()
{
    for (int i = 0; i < NodeCount; i++)
    {
        bool FoundUnsort = false;

        for (int j = 0; j < NodeCount - i - 1; j++)
        {
            if (Nodes[j].Value > Nodes[j + 1].Value)
            {

                DrawColorNodes(j, 1, 0, 0);

                DrawColorNodes(j + 1, 1, 0, 0);

                FoundUnsort = true;

            }

            else
            {
                DrawColorNodes(j, 0, 1, 0);

                DrawColorNodes(j + 1, 0, 1, 0);

            }
        }

        if (FoundUnsort)
        {
            break;
        }
    }

}

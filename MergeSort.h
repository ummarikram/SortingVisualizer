#pragma once

void Visualizer::DrawMergeSort(int RunCheckCurrSize, int RunCheckLeftStart)
{
    int curr_size;  // For current size of subarrays to be merged 
                // curr_size varies from 1 to n/2 
    int left_start; // For picking starting index of left subarray 
                    // to be merged 

    if (RunCheckCurrSize > NodeCount - 1)
    {
        for (int i = 0; i < NodeCount; i++)
        {
            DrawColorNodes(i, 0, 1, 0);
        }
    }

    else
    {

        // Merge subarrays in bottom up manner.  First merge subarrays of 
        // size 1 to create sorted subarrays of size 2, then merge subarrays 
        // of size 2 to create sorted subarrays of size 4, and so on. 
        for (curr_size = RunCheckCurrSize; curr_size <= NodeCount - 1; curr_size = 2 * curr_size)
        {
            // Pick starting point of different subarrays of current size 
            for (left_start = RunCheckLeftStart; left_start < NodeCount - 1; left_start += 2 * curr_size)
            {
                // Find ending point of left subarray. mid+1 is starting  
                // point of right 
                int mid = min(left_start + curr_size - 1, NodeCount - 1);

                int right_end = min(left_start + 2 * curr_size - 1, NodeCount - 1);

                // Merge Subarrays arr[left_start...mid] & arr[mid+1...right_end] 

                for (int i = 0; i < NodeCount; i++)
                {
                    if ((i >= left_start && i <= mid) || (i >= mid + 2 && i <= right_end))
                    {
                        DrawColorNodes(i, 0, 1, 0);
                    }
                    else
                    {
                        DrawColorNodes(i, 1, 0, 0);
                    }
                }

                break;

            }


            break;

        }

    }

}

// Merge two subarrays L and M into arr
void Visualizer::Merge(int p, int q, int r)
{
    // Create L ← A[p..q] and M ← A[q+1..r]
    int n1 = q - p + 1;
    int n2 = r - q;

    Node* L = new Node[n1];
    Node* M = new Node[n2];

    for (int i = 0; i < n1; i++)
    {
        Copy(Nodes[p + i], L[i]);

    }
    for (int j = 0; j < n2; j++)
    {
        Copy(Nodes[q + 1 + j], M[j]);
    }

    // Maintain current index of sub-arrays and main array
    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    // Until we reach either end of either L or M, pick larger among
    // elements L and M and place them in the correct position at A[p..r]
    while (i < n1 && j < n2)
    {

        if (L[i].Value <= M[j].Value)
        {
            Copy(L[i], Nodes[k]);

            i++;

        }

        else
        {
            Copy(M[j], Nodes[k]);

            j++;

        }

        k++;


    }

    // When we run out of elements in either L or M,
    // pick up the remaining elements and put in A[p..r]
    while (i < n1)
    {
        Copy(L[i], Nodes[k]);
        i++;
        k++;
    }

    while (j < n2)
    {
        Copy(M[j], Nodes[k]);
        j++;
        k++;
    }

    delete[] L; delete[] M;
}

// Divide the array into two subarrays, sort them and merge them
void Visualizer::MergeSortNodes(int& RunCheckCurrSize, int& RunCheckLeftStart)
{
    int curr_size;  // For current size of subarrays to be merged 
                    // curr_size varies from 1 to n/2 
    int left_start; // For picking starting index of left subarray 
                    // to be merged 


    // Merge subarrays in bottom up manner.  First merge subarrays of 
    // size 1 to create sorted subarrays of size 2, then merge subarrays 
    // of size 2 to create sorted subarrays of size 4, and so on. 
    for (curr_size = RunCheckCurrSize; curr_size <= NodeCount - 1; curr_size = 2 * curr_size)
    {
        // Pick starting point of different subarrays of current size 
        for (left_start = RunCheckLeftStart; left_start < NodeCount - 1; left_start += 2 * curr_size)
        {
            // Find ending point of left subarray. mid+1 is starting  
            // point of right 
            int mid = min(left_start + curr_size - 1, NodeCount - 1);

            int right_end = min(left_start + 2 * curr_size - 1, NodeCount - 1);

            // Merge Subarrays arr[left_start...mid] & arr[mid+1...right_end] 
            Merge(left_start, mid, right_end);

            RunCheckLeftStart = left_start + 2 * curr_size;

            break;

        }

        if (RunCheckLeftStart >= NodeCount - 1)
        {
            RunCheckCurrSize = 2 * curr_size;
            RunCheckLeftStart = 0;
        }

        break;

    }

}
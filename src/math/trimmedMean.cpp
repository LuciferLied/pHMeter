float trimmedMean(int *values, int n, float trimFraction)
{
    //if (n <= 0) return NAN;

    // Copy so we don't destroy original data
    float sorted[n];
    for (int i = 0; i < n; i++)
        sorted[i] = values[i];

    // Simple sort (insertion sort — fine for ~360 samples)
    for (int i = 1; i < n; i++)
    {
        float key = sorted[i];
        int j = i - 1;
        while (j >= 0 && sorted[j] > key)
        {
            sorted[j + 1] = sorted[j];
            j--;
        }
        sorted[j + 1] = key;
    }

    int trim = (int)(n * trimFraction);
    int start = trim;
    int end = n - trim;

    float sum = 0;
    int count = 0;

    for (int i = start; i < end; i++)
    {
        sum += sorted[i];
        count++;
    }

    return sum / count;
}
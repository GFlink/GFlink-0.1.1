
package CUDAWrapper.runtime;

/**
 * CUDA Profiler Output modes
 */
public class cudaOutputMode
{
    /**
     * Output mode Key-Value pair format.
     */
    public static final int cudaKeyValuePair    = 0x00;

    /**
     * Output mode Comma separated values format.
     */
    public static final int cudaCSV             = 0x01;

    /**
     * Returns the String identifying the given cudaOutputMode
     *
     * @param n The cudaOutputMode
     * @return The String identifying the given cudaOutputMode
     */
    public static String stringFor(int n)
    {
        switch (n)
        {
            case cudaKeyValuePair: return "cudaKeyValuePair";
            case cudaCSV: return "cudaCSV";
        }
        return "INVALID cudaOutputMode: "+n;
    }

    /**
     * Private constructor to prevent instantiation.
     */
    private cudaOutputMode()
    {
    }

}


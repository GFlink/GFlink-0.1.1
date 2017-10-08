

package CUDAWrapper.runtime;

/**
 * CUDA memory types
 */
public class cudaMemoryType
{
    /**
     *  Host memory
     */
    public static final int cudaMemoryTypeHost   = 1;

    /**
     * Device memory
     */
    public static final int cudaMemoryTypeDevice = 2;

    /**
     * Returns the String identifying the given cudaMemoryType
     *
     * @param k The cudaMemoryType
     * @return The String identifying the given cudaMemoryType
     */
    public static String stringFor(int k)
    {
        switch (k)
        {
            case cudaMemoryTypeHost: return "cudaMemoryTypeHost";
            case cudaMemoryTypeDevice: return "cudaMemoryTypeDevice";
        }
        return "INVALID cudaMemoryType: "+k;
    }

    /**
     * Private constructor to prevent instantiation.
     */
    private cudaMemoryType()
    {
    }

}

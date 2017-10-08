

package CUDAWrapper.runtime;

/**
 * Shared memory configurations
 */
public class cudaSharedMemConfig
{
    /**
     * Set default shared memory bank size
     */
    public static final int cudaSharedMemBankSizeDefault   = 0;

    /**
     *  Set shared memory bank width to four bytes
     */
    public static final int cudaSharedMemBankSizeFourByte = 1;

    /**
     * Set shared memory bank width to eight bytes
     */
    public static final int cudaSharedMemBankSizeEightByte     = 2;

    /**
     * Returns the String identifying the given cudaSharedMemConfig
     *
     * @param n The cudaSharedMemConfig
     * @return The String identifying the given cudaSharedMemConfig
     */
    public static String stringFor(int n)
    {
        switch (n)
        {
            case cudaSharedMemBankSizeDefault: return "cudaSharedMemBankSizeDefault";
            case cudaSharedMemBankSizeFourByte: return "cudaSharedMemBankSizeFourByte";
            case cudaSharedMemBankSizeEightByte: return "cudaSharedMemBankSizeEightByte";
        }
        return "INVALID cudaSharedMemConfig: "+n;
    }

    /**
     * Private constructor to prevent instantiation.
     */
    private cudaSharedMemConfig()
    {
    }

}

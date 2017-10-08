package CUDAWrapper.runtime;

/**
 * CUDA device compute modes.<br />
 * <br />
 * Most comments are taken from the CUDA reference manual.<br />
 *
 * @see cudaDeviceProp#computeMode
 */
public class cudaComputeMode
{
    /**
     * Default compute mode (Multiple threads can use {@link CUDAWrapper#cudaSetDevice(int)} with this device)
     */
    public static final int cudaComputeModeDefault    =   0;

    /**
     * Compute-exclusive mode (Only one thread will be able to use {@link CUDAWrapper#cudaSetDevice(int)} with this device)
     */
    public static final int cudaComputeModeExclusive  =   1;

    /**
     * Compute-prohibited mode (No threads can use {@link CUDAWrapper#cudaSetDevice(int)} with this device)
     */
    public static final int cudaComputeModeProhibited =   2;

    /**
     * Compute-exclusive-process mode (Many threads in one process will be able to use ::cudaSetDevice() with this device)
     */
    public static final int cudaComputeModeExclusiveProcess = 3;

    /**
     * Returns the String identifying the given cudaComputeMode
     *
     * @param n The cudaComputeMode
     * @return The String identifying the given cudaComputeMode
     */
    public static String stringFor(int n)
    {
        switch (n)
        {
            case cudaComputeModeDefault: return "cudaComputeModeDefault";
            case cudaComputeModeExclusive: return "cudaComputeModeExclusive";
            case cudaComputeModeProhibited: return "cudaComputeModeProhibited";
            case cudaComputeModeExclusiveProcess: return "cudaComputeModeExclusiveProcess";
        }
        return "INVALID cudaComputeMode: "+n;
    }

    /**
     * Private constructor to prevent instantiation.
     */
    private cudaComputeMode()
    {
    }

};


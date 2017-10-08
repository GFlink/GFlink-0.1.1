package CUDAWrapper.runtime;

/**
 * CUDA function cache configurations
 */
public class cudaFuncCache
{
    /**
     * Default function cache configuration, no preference
     */
    public static final int cudaFuncCachePreferNone   = 0;


    /**
     * Prefer larger shared memory and smaller L1 cache
     */
    public static final int cudaFuncCachePreferShared = 1;


    /**
     * Prefer larger L1 cache and smaller shared memory
     */
    public static final int cudaFuncCachePreferL1     = 2;

    /**
     * Prefer equal size L1 cache and shared memory
     */
    public static final int cudaFuncCachePreferEqual  = 3;

    /**
     * Returns the String identifying the given cudaFuncCache
     *
     * @param n The cudaFuncCache
     * @return The String identifying the given cudaFuncCache
     */
    public static String stringFor(int n)
    {
        switch (n)
        {
            case cudaFuncCachePreferNone: return "cudaFuncCachePreferNone";
            case cudaFuncCachePreferShared: return "cudaFuncCachePreferShared";
            case cudaFuncCachePreferL1: return "cudaFuncCachePreferL1";
            case cudaFuncCachePreferEqual: return "cudaFuncCachePreferEqual";
        }
        return "INVALID cudaFuncCache: "+n;
    }

    /**
     * Private constructor to prevent instantiation.
     */
    private cudaFuncCache()
    {
    }

}

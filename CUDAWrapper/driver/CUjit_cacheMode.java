
package CUDAWrapper.driver;

/**
 * Caching modes for dlcm
 */
public class CUjit_cacheMode
{
    /**
     * Compile with no -dlcm flag specified
     */
    public static final int CU_JIT_CACHE_OPTION_NONE = 0;

    /**
     * Compile with L1 cache disabled
     */
    public static final int CU_JIT_CACHE_OPTION_CG = 1;

    /**
     * Compile with L1 cache enabled
     */
    public static final int CU_JIT_CACHE_OPTION_CA = 2;

    /**
     * Returns the String identifying the given CUjit_cacheMode
     *
     * @param n The CUjit_cacheMode
     * @return The String identifying the given CUjit_cacheMode
     */
    public static String stringFor(int n)
    {
        switch (n)
        {
            case CU_JIT_CACHE_OPTION_NONE: return "CU_JIT_CACHE_OPTION_NONE";
            case CU_JIT_CACHE_OPTION_CG: return "CU_JIT_CACHE_OPTION_CG";
            case CU_JIT_CACHE_OPTION_CA: return "CU_JIT_CACHE_OPTION_CA";
        }
        return "INVALID CUjit_cacheMode: "+n;
    }

    /**
     * Private constructor to prevent instantiation
     */
    private CUjit_cacheMode()
    {

    }
}

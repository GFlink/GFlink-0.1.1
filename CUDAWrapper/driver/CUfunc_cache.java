

package CUDAWrapper.driver;

/**
 * Function cache configurations.<br />
 * <br />
 * Most comments are taken from the CUDA reference manual.
 */
public class CUfunc_cache
{
    /**
     * No preference for shared memory or L1 (default)
     */
    public static final int CU_FUNC_CACHE_PREFER_NONE   = 0x00;

    /**
     * Prefer larger shared memory and smaller L1 cache
     */
    public static final int CU_FUNC_CACHE_PREFER_SHARED = 0x01;

    /**
     * Prefer larger L1 cache and smaller shared memory
     */
    public static final int CU_FUNC_CACHE_PREFER_L1     = 0x02;

    /**
     * Prefer equal sized L1 cache and shared memory
     */
    public static final int CU_FUNC_CACHE_PREFER_EQUAL   = 0x03;

    /**
     * Returns the String identifying the given CUfunc_cache
     *
     * @param n The CUfunc_cache
     * @return The String identifying the given CUfunc_cache
     */
    public static String stringFor(int n)
    {
        switch (n)
        {
            case CU_FUNC_CACHE_PREFER_NONE: return "CU_FUNC_CACHE_PREFER_NONE";
            case CU_FUNC_CACHE_PREFER_SHARED: return "CU_FUNC_CACHE_PREFER_SHARED";
            case CU_FUNC_CACHE_PREFER_L1: return "CU_FUNC_CACHE_PREFER_L1";
            case CU_FUNC_CACHE_PREFER_EQUAL: return "CU_FUNC_CACHE_PREFER_EQUAL";
        }
        return "INVALID CUfunc_cache: "+n;
    }

    /**
     * Private constructor to prevent instantiation.
     */
    private CUfunc_cache()
    {
    }

};


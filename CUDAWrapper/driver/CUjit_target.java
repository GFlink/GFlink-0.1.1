
package CUDAWrapper.driver;

/**
 * Online compilation targets.<br />
 * <br />
 * Most comments are taken from the CUDA reference manual.<br />
 *
 * @see CUDAWrapperDriver#cuModuleLoadDataEx
 */
public class CUjit_target
{

    /**
     * Compute device class 1.0
     */
    public static final int CU_TARGET_COMPUTE_10 = 10;

    /**
     * Compute device class 1.1
     */
    public static final int CU_TARGET_COMPUTE_11 = 11;

    /**
     * Compute device class 1.2
     */
    public static final int CU_TARGET_COMPUTE_12 = 12;

    /**
     * Compute device class 1.3
     */
    public static final int CU_TARGET_COMPUTE_13 = 13;

    /**
     * Compute device class 2.0
     */
    public static final int CU_TARGET_COMPUTE_20 = 20;

    /**
     * Compute device class 2.1
     */
    public static final int CU_TARGET_COMPUTE_21 = 21;

    /**
     * Compute device class 3.0
     */
    public static final int CU_TARGET_COMPUTE_30 = 30;

    /**
     * Compute device class 3.2
     */
    public static final int CU_TARGET_COMPUTE_32 = 32;

    /**
     * Compute device class 3.5
     */
    public static final int CU_TARGET_COMPUTE_35 = 35;

    /**
     * Compute device class 3.7
     */
    public static final int CU_TARGET_COMPUTE_37 = 37;

    /**
     * Compute device class 5.0
     */
    public static final int CU_TARGET_COMPUTE_50 = 50;

    /**
     * Compute device class 5.2
     */
    public static final int CU_TARGET_COMPUTE_52 = 52;

    /**
     * Compute device class 5.3
     */
    public static final int CU_TARGET_COMPUTE_53 = 53;

    /**
     * Compute device class 6.0. This must be removed for CUDA 7.0 toolkit.
     * See bug 1518217.
     */
    public static final int CU_TARGET_COMPUTE_60 = 60;

    /**
     * Compute device class 6.1. This must be removed for CUDA 7.0 toolkit.
     */
    public static final int CU_TARGET_COMPUTE_61 = 61;

    /**
     * Compute device class 6.2. This must be removed for CUDA 7.0 toolkit.
     */
    public static final int CU_TARGET_COMPUTE_62 = 62;

    /**
     * Returns the String identifying the given CUjit_target
     *
     * @param n The CUjit_target
     * @return The String identifying the given CUjit_target
     */
    public static String stringFor(int n)
    {
        switch (n)
        {
            case CU_TARGET_COMPUTE_10: return "CU_TARGET_COMPUTE_10";
            case CU_TARGET_COMPUTE_11: return "CU_TARGET_COMPUTE_11";
            case CU_TARGET_COMPUTE_12: return "CU_TARGET_COMPUTE_12";
            case CU_TARGET_COMPUTE_13: return "CU_TARGET_COMPUTE_13";
            case CU_TARGET_COMPUTE_20: return "CU_TARGET_COMPUTE_20";
            case CU_TARGET_COMPUTE_21: return "CU_TARGET_COMPUTE_21";
            case CU_TARGET_COMPUTE_30: return "CU_TARGET_COMPUTE_30";
            case CU_TARGET_COMPUTE_32: return "CU_TARGET_COMPUTE_32";
            case CU_TARGET_COMPUTE_35: return "CU_TARGET_COMPUTE_35";
            case CU_TARGET_COMPUTE_37: return "CU_TARGET_COMPUTE_37";
            case CU_TARGET_COMPUTE_50: return "CU_TARGET_COMPUTE_50";
            case CU_TARGET_COMPUTE_52: return "CU_TARGET_COMPUTE_52";
            case CU_TARGET_COMPUTE_53: return "CU_TARGET_COMPUTE_53";
            case CU_TARGET_COMPUTE_60: return "CU_TARGET_COMPUTE_60";
            case CU_TARGET_COMPUTE_61: return "CU_TARGET_COMPUTE_61";
            case CU_TARGET_COMPUTE_62: return "CU_TARGET_COMPUTE_62";
        }
        return "INVALID CUjit_target: "+n;
    }

    /**
     * Private constructor to prevent instantiation.
     */
    private CUjit_target()
    {
    }

}


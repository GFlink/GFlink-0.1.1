

package CUDAWrapper.driver;

/**
 * Texture reference filtering modes.
 *
 * @see CUDAWrapperDriver#cuTexRefSetFilterMode
 * @see CUDAWrapperDriver#cuTexRefGetFilterMode
 */
public class CUfilter_mode
{

    /**
     * Point filter mode
     */
    public static final int CU_TR_FILTER_MODE_POINT = 0;

    /**
     * Linear filter mode
     */
    public static final int CU_TR_FILTER_MODE_LINEAR = 1;


    /**
     * Returns the String identifying the given CUfilter_mode
     *
     * @param n The CUfilter_mode
     * @return The String identifying the given CUfilter_mode
     */
    public static String stringFor(int n)
    {
        switch (n)
        {
            case CU_TR_FILTER_MODE_POINT: return "CU_TR_FILTER_MODE_POINT";
            case CU_TR_FILTER_MODE_LINEAR: return "CU_TR_FILTER_MODE_LINEAR";
        }
        return "INVALID CUfilter_mode: "+n;
    }

    /**
     * Private constructor to prevent instantiation.
     */
    private CUfilter_mode()
    {
    }

}

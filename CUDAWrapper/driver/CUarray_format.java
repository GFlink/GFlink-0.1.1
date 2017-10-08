
package CUDAWrapper.driver;

/**
 * Array formats.<br />
 * <br />
 * Most comments are taken from the CUDA reference manual.
 *
 * @see CUDA_ARRAY_DESCRIPTOR
 * @see CUDA_ARRAY3D_DESCRIPTOR
 */
public class CUarray_format
{

    /**
     * Unsigned 8-bit integers
     */
    public static final int CU_AD_FORMAT_UNSIGNED_INT8  = 0x01;

    /**
     * Unsigned 16-bit integers
     */
    public static final int CU_AD_FORMAT_UNSIGNED_INT16 = 0x02;

    /**
     * Unsigned 32-bit integers
     */
    public static final int CU_AD_FORMAT_UNSIGNED_INT32 = 0x03;

    /**
     * Signed 8-bit integers
     */
    public static final int CU_AD_FORMAT_SIGNED_INT8    = 0x08;

    /**
     * Signed 16-bit integers
     */
    public static final int CU_AD_FORMAT_SIGNED_INT16   = 0x09;

    /**
     * Signed 32-bit integers
     */
    public static final int CU_AD_FORMAT_SIGNED_INT32   = 0x0a;

    /**
     * 16-bit floating point
     */
    public static final int CU_AD_FORMAT_HALF           = 0x10;

    /**
     * 32-bit floating point
     */
    public static final int CU_AD_FORMAT_FLOAT          = 0x20;


    /**
     * Returns the String identifying the given CUarray_format
     *
     * @param n The CUarray_format
     * @return The String identifying the given CUarray_format
     */
    public static String stringFor(int n)
    {
        switch (n)
        {
            case CU_AD_FORMAT_UNSIGNED_INT8 : return "CU_AD_FORMAT_UNSIGNED_INT8";
            case CU_AD_FORMAT_UNSIGNED_INT16 : return "CU_AD_FORMAT_UNSIGNED_INT16";
            case CU_AD_FORMAT_UNSIGNED_INT32 : return "CU_AD_FORMAT_UNSIGNED_INT32";
            case CU_AD_FORMAT_SIGNED_INT8 : return "CU_AD_FORMAT_SIGNED_INT8";
            case CU_AD_FORMAT_SIGNED_INT16 : return "CU_AD_FORMAT_SIGNED_INT16";
            case CU_AD_FORMAT_SIGNED_INT32 : return "CU_AD_FORMAT_SIGNED_INT32";
            case CU_AD_FORMAT_HALF : return "CU_AD_FORMAT_HALF";
            case CU_AD_FORMAT_FLOAT : return "CU_AD_FORMAT_FLOAT";
        }
        return "INVALID CUarray_format: "+n;
    }

    /**
     * Private constructor to prevent instantiation.
     */
    private CUarray_format()
    {
    }

}

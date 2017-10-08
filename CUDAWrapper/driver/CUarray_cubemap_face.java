
package CUDAWrapper.driver;

/**
 * Array indices for cube faces
 */
public class CUarray_cubemap_face
{
    /**
     * Positive X face of cubemap
     */
    public static final int CU_CUBEMAP_FACE_POSITIVE_X  = 0x00;

    /**
     * Negative X face of cubemap
     */
    public static final int CU_CUBEMAP_FACE_NEGATIVE_X  = 0x01;

    /**
     * Positive Y face of cubemap
     */
    public static final int CU_CUBEMAP_FACE_POSITIVE_Y  = 0x02;

    /**
     * Negative Y face of cubemap
     */
    public static final int CU_CUBEMAP_FACE_NEGATIVE_Y  = 0x03;

    /**
     * Positive Z face of cubemap
     */
    public static final int CU_CUBEMAP_FACE_POSITIVE_Z  = 0x04;

    /**
     * Negative Z face of cubemap
     */
    public static final int CU_CUBEMAP_FACE_NEGATIVE_Z  = 0x05;


    /**
     * Returns the String identifying the given CUarray_cubemap_face
     *
     * @param n The CUarray_cubemap_face
     * @return The String identifying the given CUarray_cubemap_face
     */
    public static String stringFor(int n)
    {
        switch (n)
        {
            case CU_CUBEMAP_FACE_POSITIVE_X: return "CU_CUBEMAP_FACE_POSITIVE_X";
            case CU_CUBEMAP_FACE_NEGATIVE_X: return "CU_CUBEMAP_FACE_NEGATIVE_X";
            case CU_CUBEMAP_FACE_POSITIVE_Y: return "CU_CUBEMAP_FACE_POSITIVE_Y";
            case CU_CUBEMAP_FACE_NEGATIVE_Y: return "CU_CUBEMAP_FACE_NEGATIVE_Y";
            case CU_CUBEMAP_FACE_POSITIVE_Z: return "CU_CUBEMAP_FACE_POSITIVE_Z";
            case CU_CUBEMAP_FACE_NEGATIVE_Z: return "CU_CUBEMAP_FACE_NEGATIVE_Z";
        }
        return "INVALID CUarray_cubemap_face: "+n;
    }

    /**
     * Private constructor to prevent instantiation.
     */
    private CUarray_cubemap_face()
    {
    }


}


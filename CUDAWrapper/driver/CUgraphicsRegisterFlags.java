

package CUDAWrapper.driver;

/**
 * Flags for mapping and unmapping interop resources
 */
public class CUgraphicsRegisterFlags
{
    public static final int CU_GRAPHICS_REGISTER_FLAGS_NONE  = 0x00;

    public static final int CU_GRAPHICS_REGISTER_FLAGS_READ_ONLY     = 0x01;

    public static final int CU_GRAPHICS_REGISTER_FLAGS_WRITE_DISCARD = 0x02;

    public static final int CU_GRAPHICS_REGISTER_FLAGS_SURFACE_LDST  = 0x04;

    public static final int CU_GRAPHICS_REGISTER_FLAGS_TEXTURE_GATHER = 0x08;

    /**
     * Returns the String identifying the given CUgraphicsRegisterFlags
     *
     * @param n The CUgraphicsRegisterFlags
     * @return The String identifying the given CUgraphicsRegisterFlags
     */
    public static String stringFor(int n)
    {
        if (n == 0)
        {
            return "CU_GRAPHICS_REGISTER_FLAGS_NONE";
        }
        String result = "";
        if ((n & CU_GRAPHICS_REGISTER_FLAGS_READ_ONLY    ) != 0) result += "CU_GRAPHICS_REGISTER_FLAGS_READ_ONLY ";
        if ((n & CU_GRAPHICS_REGISTER_FLAGS_WRITE_DISCARD) != 0) result += "CU_GRAPHICS_REGISTER_FLAGS_WRITE_DISCARD ";
        if ((n & CU_GRAPHICS_REGISTER_FLAGS_SURFACE_LDST ) != 0) result += "CU_GRAPHICS_REGISTER_FLAGS_SURFACE_LDST ";
        if ((n & CU_GRAPHICS_REGISTER_FLAGS_TEXTURE_GATHER ) != 0) result += "CU_GRAPHICS_REGISTER_FLAGS_TEXTURE_GATHER ";
        return result;
    }

    /**
     * Private constructor to prevent instantiation.
     */
    private CUgraphicsRegisterFlags()
    {
    }


}




package CUDAWrapper.driver;

/**
 * Flags to map or unmap a resource
 *
 * @deprecated As of CUDA 3.0
 */
public class CUGLmap_flags
{
    public static final int CU_GL_MAP_RESOURCE_FLAGS_NONE          = 0x00;
    public static final int CU_GL_MAP_RESOURCE_FLAGS_READ_ONLY     = 0x01;
    public static final int CU_GL_MAP_RESOURCE_FLAGS_WRITE_DISCARD = 0x02;

    /**
     * Returns the String identifying the given CUGLmap_flags
     *
     * @param n The CUGLmap_flags
     * @return The String identifying the given CUGLmap_flags
     */
    public static String stringFor(int n)
    {
        if (n == 0)
        {
            return "CU_GL_MAP_RESOURCE_FLAGS_NONE";
        }
        String result = "";
        if ((n & CU_GL_MAP_RESOURCE_FLAGS_READ_ONLY    ) != 0) result += "CU_GL_MAP_RESOURCE_FLAGS_READ_ONLY ";
        if ((n & CU_GL_MAP_RESOURCE_FLAGS_WRITE_DISCARD) != 0) result += "CU_GL_MAP_RESOURCE_FLAGS_WRITE_DISCARD ";
        return result;
    }

    /**
     * Private constructor to prevent instantiation.
     */
    private CUGLmap_flags()
    {
    }


}

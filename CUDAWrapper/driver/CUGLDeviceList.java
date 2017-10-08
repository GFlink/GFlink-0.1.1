
package CUDAWrapper.driver;

/**
 * CUDA devices corresponding to an OpenGL device
 */
public class CUGLDeviceList
{
    /**
     * The CUDA devices for all GPUs used by the current OpenGL context
     */
    public static final int CU_GL_DEVICE_LIST_ALL            = 0x01;

    /**
     * The CUDA devices for the GPUs used by the current OpenGL context
     * in its currently rendering frame
     */
    public static final int CU_GL_DEVICE_LIST_CURRENT_FRAME  = 0x02;

    /**
     * The CUDA devices for the GPUs to be used by the current OpenGL
     * context in the next frame
     */
    public static final int CU_GL_DEVICE_LIST_NEXT_FRAME     = 0x03;

    /**
     * Returns the String identifying the given CUGLDeviceList
     *
     * @param n The CUGLDeviceList
     * @return The String identifying the given CUGLDeviceList
     */
    public static String stringFor(int n)
    {
        switch (n)
        {
            case CU_GL_DEVICE_LIST_ALL: return "CU_GL_DEVICE_LIST_ALL";
            case CU_GL_DEVICE_LIST_CURRENT_FRAME: return "CU_GL_DEVICE_LIST_CURRENT_FRAME";
            case CU_GL_DEVICE_LIST_NEXT_FRAME: return "CU_GL_DEVICE_LIST_NEXT_FRAME";
        }
        return "INVALID CUfunction_attribute: "+n;
    }

    /**
     * Private constructor to prevent instantiation.
     */
    private CUGLDeviceList()
    {
    }


}
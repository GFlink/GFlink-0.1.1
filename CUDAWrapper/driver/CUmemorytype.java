

package CUDAWrapper.driver;

/**
 * Memory types.
 *
 * @see CUDAWrapperDriver#cuMemcpyHtoD
 * @see CUDAWrapperDriver#cuMemcpyDtoH
 * @see CUDAWrapperDriver#cuMemcpyDtoD
 * @see CUDAWrapperDriver#cuMemcpyDtoA
 * @see CUDAWrapperDriver#cuMemcpyAtoD
 * @see CUDAWrapperDriver#cuMemcpyAtoH
 * @see CUDAWrapperDriver#cuMemcpyHtoA
 * @see CUDAWrapperDriver#cuMemcpyAtoA
 * @see CUDAWrapperDriver#cuMemcpy2D
 * @see CUDAWrapperDriver#cuMemcpy2DAsync
 * @see CUDAWrapperDriver#cuMemcpy3D
 * @see CUDAWrapperDriver#cuMemcpy3DAsync
 */
public class CUmemorytype
{
    /**
     * Host memory
     */
    public static final int CU_MEMORYTYPE_HOST = 0x01;

    /**
     * Device memory
     */
    public static final int CU_MEMORYTYPE_DEVICE = 0x02;

    /**
     * Array memory
     */
    public static final int CU_MEMORYTYPE_ARRAY = 0x03;

    /**
     * Unified device or host memory
     */
    public static final int CU_MEMORYTYPE_UNIFIED = 0x04;

    /**
     * Returns the String identifying the given CUmemorytype
     *
     * @param n The CUmemorytype
     * @return The String identifying the given CUmemorytype
     */
    public static String stringFor(int n)
    {
        switch (n)
        {
            case CU_MEMORYTYPE_HOST: return "CU_MEMORYTYPE_HOST";
            case CU_MEMORYTYPE_DEVICE: return "CU_MEMORYTYPE_DEVICE";
            case CU_MEMORYTYPE_ARRAY: return "CU_MEMORYTYPE_ARRAY";
            case CU_MEMORYTYPE_UNIFIED: return "CU_MEMORYTYPE_UNIFIED";
        }
        return "INVALID CUmemorytype: "+n;
    }

    /**
     * Private constructor to prevent instantiation.
     */
    private CUmemorytype()
    {
    }

}

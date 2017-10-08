
package CUDAWrapper.driver;

/**
 * Device code formats
 */
public class CUjitInputType
{
    /**
     * Compiled device-class-specific device code<br />
     * Applicable options: none
     */
    public static final int CU_JIT_INPUT_CUBIN = 0;

    /**
     * PTX source code<br />
     * Applicable options: PTX compiler options
     */
    public static final int CU_JIT_INPUT_PTX = 1;

    /**
     * Bundle of multiple cubins and/or PTX of some device code<br />
     * Applicable options: PTX compiler options, ::CU_JIT_FALLBACK_STRATEGY
     */
    public static final int CU_JIT_INPUT_FATBINARY = 2;

    /**
     * Host object with embedded device code<br />
     * Applicable options: PTX compiler options, ::CU_JIT_FALLBACK_STRATEGY
     */
    public static final int CU_JIT_INPUT_OBJECT = 3;

    /**
     * Archive of host objects with embedded device code<br />
     * Applicable options: PTX compiler options, ::CU_JIT_FALLBACK_STRATEGY
     */
    public static final int CU_JIT_INPUT_LIBRARY = 4;

    /**
     * Returns the String identifying the given CUjitInputType
     *
     * @param n The CUjitInputType
     * @return The String identifying the given CUjitInputType
     */
    public static String stringFor(int n)
    {
        switch (n)
        {
            case CU_JIT_INPUT_CUBIN: return "CU_JIT_INPUT_CUBIN";
            case CU_JIT_INPUT_PTX: return "CU_JIT_INPUT_PTX";
            case CU_JIT_INPUT_FATBINARY: return "CU_JIT_INPUT_FATBINARY";
            case CU_JIT_INPUT_OBJECT: return "CU_JIT_INPUT_OBJECT";
            case CU_JIT_INPUT_LIBRARY: return "CU_JIT_INPUT_LIBRARY";
        }
        return "INVALID CUjitInputType: "+n;
    }

    /**
     * Private constructor to prevent instantiation
     */
    private CUjitInputType()
    {

    }


}

package CUDAWrapper.driver;

/**
 * Texture reference addressing modes.<br />
 * <br />
 * Most comments are taken from the CUDA reference manual.
 *
 * @see CUDAWrapperDriver#cuTexRefSetAddressMode
 * @see CUDAWrapperDriver#cuTexRefGetAddressMode
 */
public class CUaddress_mode
{
    /**
     * Wrapping address mode
     */
    public static final int CU_TR_ADDRESS_MODE_WRAP = 0;

    /**
     * Clamp to edge address mode
     */
    public static final int CU_TR_ADDRESS_MODE_CLAMP = 1;

    /**
     * Mirror address mode
     */
    public static final int CU_TR_ADDRESS_MODE_MIRROR = 2;


    /**
     * Returns the String identifying the given CUaddress_mode
     *
     * @param n The CUaddress_mode
     * @return The String identifying the given CUaddress_mode
     */
    public static String stringFor(int n)
    {
        switch (n)
        {
            case CU_TR_ADDRESS_MODE_WRAP: return "CU_TR_ADDRESS_MODE_WRAP";
            case CU_TR_ADDRESS_MODE_CLAMP: return "CU_TR_ADDRESS_MODE_CLAMP";
            case CU_TR_ADDRESS_MODE_MIRROR: return "CU_TR_ADDRESS_MODE_MIRROR";
        }
        return "INVALID CUaddress_mode: "+n;
    }

    /**
     * Private constructor to prevent instantiation.
     */
    private CUaddress_mode()
    {
    }

}

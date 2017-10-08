

package CUDAWrapper.driver;

/**
 * Java port of a CUipcMemHandle
 */
public class CUipcMemHandle
{
    private static final int CU_IPC_HANDLE_SIZE = 64;

    // This field is only used on the native side. Nobody
    // knows whether CUDA already uses this data, but
    // presumably, it does
    @SuppressWarnings("unused")
    private byte reserved[] = new byte[CU_IPC_HANDLE_SIZE];

    /**
     * Creates a new, uninitialized CUipcMemHandle
     */
    public CUipcMemHandle()
    {
    }

    /**
     * Returns a String representation of this object.
     *
     * @return A String representation of this object.
     */
    @Override
    public String toString()
    {
        return super.toString();
    }

}

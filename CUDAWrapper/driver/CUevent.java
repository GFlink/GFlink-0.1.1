

package CUDAWrapper.driver;

import CUDAWrapper.NativePointerObject;
import CUDAWrapper.runtime.cudaEvent_t;

/**
 * Java port of a CUevent.
 *
 * @see CUDAWrapperDriver#cuEventCreate
 * @see CUDAWrapperDriver#cuEventRecord
 * @see CUDAWrapperDriver#cuEventQuery
 * @see CUDAWrapperDriver#cuEventSynchronize
 * @see CUDAWrapperDriver#cuEventDestroy
 * @see CUDAWrapperDriver#cuEventElapsedTime
 */
public class CUevent extends NativePointerObject
{
    /**
     * Creates a new, uninitialized CUevent
     */
    public CUevent()
    {
    }

    /**
     * Creates a CUevent for the given {@link cudaEvent_t}. This
     * corresponds to casting a cudaEvent_t to a CUevent.
     *
     * @param event The other event
     */
    public CUevent(cudaEvent_t event)
    {
        super(event);
    }

    /**
     * Returns a String representation of this object.
     *
     * @return A String representation of this object.
     */
    @Override
    public String toString()
    {
        return "CUevent["+
            "nativePointer=0x"+Long.toHexString(getNativePointer())+"]";
    }

}

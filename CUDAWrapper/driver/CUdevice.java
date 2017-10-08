

package CUDAWrapper.driver;

import CUDAWrapper.NativePointerObject;

/**
 * Java port of a CUdevice.
 *
 * @see CUDAWrapperDriver#cuDeviceGet
 * @see CUDAWrapperDriver#cuDeviceComputeCapability
 * @see CUDAWrapperDriver#cuDeviceGetAttribute
 * @see CUDAWrapperDriver#cuDeviceGetCount
 * @see CUDAWrapperDriver#cuDeviceGetName
 * @see CUDAWrapperDriver#cuDeviceGetProperties
 * @see CUDAWrapperDriver#cuDeviceTotalMem
 */
public class CUdevice extends NativePointerObject
{
    /**
     * Creates a new, uninitialized CUdevice
     */
    public CUdevice()
    {
    }

    /**
     * Package-private constructor to create a CUdevice with the given
     * value as its internal pointer. This is ONLY used for 
     * {@link CUDAWrapperDriver#CU_DEVICE_CPU}
     */
    CUdevice(long value)
    {
        super(value);
    }

    /**
     * Returns a String representation of this object.
     *
     * @return A String representation of this object.
     */
    @Override
    public String toString()
    {
        return "CUdevice["+
            "nativePointer=0x"+Long.toHexString(getNativePointer())+"]";
    }

}



package CUDAWrapper.driver;

import CUDAWrapper.NativePointerObject;

/**
 * Java port of a CUtexref.
 *
 * @see CUDAWrapperDriver#cuTexRefCreate
 * @see CUDAWrapperDriver#cuTexRefDestroy
 * @see CUDAWrapperDriver#cuTexRefSetArray
 * @see CUDAWrapperDriver#cuTexRefSetAddress
 * @see CUDAWrapperDriver#cuTexRefSetFormat
 * @see CUDAWrapperDriver#cuTexRefSetAddressMode
 * @see CUDAWrapperDriver#cuTexRefSetFilterMode
 * @see CUDAWrapperDriver#cuTexRefSetFlags
 * @see CUDAWrapperDriver#cuTexRefGetAddress
 * @see CUDAWrapperDriver#cuTexRefGetArray
 * @see CUDAWrapperDriver#cuTexRefGetAddressMode
 * @see CUDAWrapperDriver#cuTexRefGetFilterMode
 * @see CUDAWrapperDriver#cuTexRefGetFormat
 * @see CUDAWrapperDriver#cuTexRefGetFlags
 */
public class CUtexref extends NativePointerObject
{
    /**
     * Creates a new, uninitialized CUtexref
     */
    public CUtexref()
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
        return "CUtexref["+
            "nativePointer=0x"+Long.toHexString(getNativePointer())+"]";
    }

}

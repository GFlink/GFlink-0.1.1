
package CUDAWrapper.driver;

import CUDAWrapper.NativePointerObject;

/**
 * Java port of a CUsurfref.
 *
 * @see CUDAWrapperDriver#cuSurfRefGetArray(CUarray, CUsurfref)
 * @see CUDAWrapperDriver#cuSurfRefSetArray(CUsurfref, CUarray, int)
 */
public class CUsurfref extends NativePointerObject
{
    /**
     * Creates a new, uninitialized CUtexref
     */
    public CUsurfref()
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
        return "CUsurfref["+
            "nativePointer=0x"+Long.toHexString(getNativePointer())+"]";
    }

}

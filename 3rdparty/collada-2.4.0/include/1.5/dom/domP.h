#ifndef __dom150P_h__
#define __dom150P_h__

#include <dae/daeDocument.h>
#include <1.5/dom/domTypes.h>
#include <1.5/dom/domElements.h>


class DAE;
namespace ColladaDOM150 {

/**
 * The p element represents primitive data for the primitive types (lines,
 * linestrips, polygons,  polylist, triangles, trifans, tristrips). The p
 * element contains indices that reference into  the parent's source elements
 * referenced by the input elements.
 */
class domP : public daeElement
{
public:
	virtual COLLADA_TYPE::TypeEnum getElementType() const { return COLLADA_TYPE::P; }
	static daeInt ID() { return 13; }
	virtual daeInt typeID() const { return ID(); }


public:	//Accessors and Mutators
	/**
	 * Gets the value of this element.
	 * @return a domList_of_uints of the value.
	 */
	domList_of_uints& getValue() { return _value; }
	/**
	 * Sets the _value of this element.
	 * @param val The new value for this element.
	 */
	void setValue( const domList_of_uints& val ) { _value = val; }

protected:  // Value
	/**
	 * The domList_of_uints value of the text data of this element. 
	 */
	domList_of_uints _value;
protected:
	/**
	 * Constructor
	 */
	domP(DAE& dae) : daeElement(dae), _value() {}
	/**
	 * Destructor
	 */
	virtual ~domP() {}
	/**
	 * Overloaded assignment operator
	 */
	virtual domP &operator=( const domP &cpy ) { (void)cpy; return *this; }

public: // STATIC METHODS
	/**
	 * Creates an instance of this class and returns a daeElementRef referencing it.
	 * @return a daeElementRef referencing an instance of this object.
	 */
	static DLLSPEC daeElementRef create(DAE& dae);
	/**
	 * Creates a daeMetaElement object that describes this element in the meta object reflection framework.
	 * If a daeMetaElement already exists it will return that instead of creating a new one. 
	 * @return A daeMetaElement describing this COLLADA element.
	 */
	static DLLSPEC daeMetaElement* registerElement(DAE& dae);
};


} // ColladaDOM150
#endif

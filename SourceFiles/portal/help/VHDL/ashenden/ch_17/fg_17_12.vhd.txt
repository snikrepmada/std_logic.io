package «element_type_simple_name»_ordered_collection_adt is

  -- template: fill in the placeholders to specialize for a particular type

  alias element_type is «element_type»;
  alias key_type is «key_type»;
  alias key_of is «key_function» [ element_type return key_type ];
  alias "<" is «less_than_function» [ key_type, key_type return boolean ];

  -- types provided by the package

  type ordered_collection_object;    -- private
  type position_object;              -- private

  type ordered_collection is access ordered_collection_object;
  type position is access position_object;

  -- operations on ordered collections

  function new_ordered_collection return ordered_collection;
  -- returns an empty ordered collection of element_type values

  procedure insert ( c : inout ordered_collection;  e : in element_type );
  -- inserts e into c in position determined by key_of(e)

  procedure get_element ( variable p : in position;  e : out element_type );
  -- returns the element value at position p in its collection

  procedure test_null_position ( variable p : in position;  is_null : out boolean );
  -- test whether p refers to no position in its collection

  procedure search ( variable c : in ordered_collection;  k : in key_type;
                     p : out position );
  -- searches for an element with key k in c, and returns the position of
  -- that element, or, if not found, a position for which test_null_position
  -- returns true

  procedure find_first ( variable c : in ordered_collection;  p : out position );
  -- returns the position of the first element of c

  procedure advance ( p : inout position );
  -- advances p to the next element in its collection,
  -- or if there are no more, sets p so that test_null_position returns true

  procedure delete ( p : inout position );
  -- deletes the element at position p from its collection, and advances p

  -- private types: pretend these are not visible

  type ordered_collection_object is
    record
      element : element_type;
      next_element, prev_element : ordered_collection;
    end record ordered_collection_object;

  type position_object is
    record
      the_collection : ordered_collection;
      current_element : ordered_collection;
    end record position_object;

end package «element_type_simple_name»_ordered_collection_adt;

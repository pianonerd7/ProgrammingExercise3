data Nestedlist a = Element a | SubList [Nestedlist a] deriving (Show, Eq)

flatten [] = []
flatten l = 
	if (head (head l)) == null
		(head l) : flatten (tail l)
	else
		flatten (head l) : flatten (tail l)




flatten [Element 1,Element 3,SubList [Element 4,SubList [SubList [Element 5],SubList []]],Element 6]
[Element 1,Element 3,Element 4,Element 5,Element 6]



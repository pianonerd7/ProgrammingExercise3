data Nestedlist a = Element a | 
										SubList [Nestedlist a] deriving (Show, Eq)

flatten :: [Nestedlist a]->[Nestedlist a]
flatten [] = []
flatten (x:xs) = myflatten x ++ myflatten (SubList xs)
myflatten (SubList []) = []
myflatten (Element e) = [Element e]
myflatten (SubList (x:xs)) = myflatten x ++ myflatten (SubList xs)

myreverse :: [Nestedlist a]->[Nestedlist a]
myreverse [] = []
myreverse (x:xs) = myreverse xs ++ myownreverse x
myownreverse (Element e) = [Element e]
myownreverse (SubList list) = [SubList (myreverse list)]

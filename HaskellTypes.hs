data Nestedlist a = Element a | 
										SubList [Nestedlist a] deriving (Show, Eq)

flatten :: [Nestedlist a]->[Nestedlist a]
flatten [] = []
flatten (x:xs) = myflatten x ++ myflatten (SubList xs)

myflatten (SubList []) = []
myflatten (Element e) = [Element e]
myflatten (SubList (x:xs)) = myflatten x ++ myflatten (SubList xs)

myreverse (SubList []) = []
myreverse (Element e) = [Element e]
--myreverse (SubList (x:xs)) = myreverse (SubList xs) : myreverse x :[]


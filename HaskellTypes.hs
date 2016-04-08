
data Nestedlist a = Element a | List [Nestedlist a] deriving (Eq, Show)




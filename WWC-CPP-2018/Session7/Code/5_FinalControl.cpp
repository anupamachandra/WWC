struct Node {   // interface class
     virtual Type type() = 0;
      //...
};

class If_statement : public Node {
public:
     Type type() override final;     // prevent further overriding
      //...
};

class Modified_if_statement : public If_statement {
public:
     Type type() override;     // error: If_statement::type() is final
      //...
};

class For_statement final : public Node {
public:
     Type type() override;
      //...
};

class Modified_for_statement : public For_statement {    // error: For_statement is final
      Type type() override;
       //...
};
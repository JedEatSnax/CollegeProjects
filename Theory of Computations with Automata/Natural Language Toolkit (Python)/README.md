# Natural Language Toolkit CFG
This project implements a context-free grammar parser that analyzes simple English sentences and generates parse trees. It demonstrates fundamental CFG concepts, including terminal/non-terminal symbols, production rules, recursive grammar structures, and structural ambiguity in natural language.

## Code Snippet
```python
sentences = [
    ['the', 'big', 'dog', 'chases', 'a', 'cat', 'in', 'the', 'park'],  # Original
    ['she', 'runs'],  # Simple intransitive verb
    ['he', 'sleeps'],  # Another intransitive
    ['the', 'red', 'ball', 'jumps'],  # Adjective + intransitive
    ['a', 'cat', 'sees', 'the', 'old', 'man', 'near', 'the', 'house']  # More complex
]

parser = nltk.ChartParser(grammar)

print("=== GRAMMAR INFORMATION ===")
print(grammar)

print("\n" + "=" * 32)
print("PARSING RESULTS WITH PARSE TREES")
print("=" * 32)

for i, sentence in enumerate(sentences, 1):
    print(f"\n--- Sentence {i}: {' '.join(sentence)} ---")

    # Parse the sentence
    trees = list(parser.parse(sentence))

    if trees:
        print(f"Parse successful. Found {len(trees)} parse tree(s).")

        # Show all parse trees
        for j, tree in enumerate(trees, 1):
            if len(trees) > 1:
                print(f"\n--- Parse Tree {j} ---")
            else:
                print("\nParse Tree:")

            tpp = TreePrettyPrinter(tree)
            print(tpp.text(unicodelines=True))
            print(f"Bracket Notation: {tree}")

        # If multiple parses exist, explain the ambiguity
        if len(trees) > 1:
            print(f"\nAmbiguity detected. This sentence has {len(trees)} different parse trees.")
            print("This sentence demonstrates structural ambiguity in CFGs.")
    else:
        print("Parse failed. The grammar does not accept the sentence.")
```

## Production Rules
- SENTENCE → NOUN_PHRASE VERB_PHRASE
- NOUN_PHRASE → PRONOUN | DETERMINANT NOUN | DETERMINANT ADJECTIVE NOUN | NOUN_PHRASE
- PREPOSITIONAL_PHRASE
- VERB_PHRASE → VERB | VERB NOUN_PHRASE | VERB_PHRASE PREPOSITIONAL_PHRASE
- PREPOSITIONAL_PHRASE → PREPOSITION NOUN_PHRASE

## Terminal Symbols (Vocabulary)
- Determinants: 'a', 'the'
- Nouns: 'cat', 'dog', 'man', 'park', 'ball', 'house', 'tree'
- Pronouns: 'he', 'she', 'it'
- Adjectives: 'big', 'small', 'happy', 'red', 'old'
- Verbs: 'loves', 'chases', 'sees', 'runs', 'sleeps', 'jumps'
- Prepositions: 'in', 'with', 'near', 'under', 'on'

## Output of `print(grammar)`
```
Grammar with 37 productions (start state = SENTENCE)
    SENTENCE -> NOUN_PHRASE VERB_PHRASE
    NOUN_PHRASE -> PRONOUN
    NOUN_PHRASE -> DETERMINANT NOUN
    NOUN_PHRASE -> DETERMINANT ADJECTIVE NOUN
    NOUN_PHRASE -> NOUN_PHRASE PREPOSITIONAL_PHRASE
    VERB_PHRASE -> VERB NOUN_PHRASE
    VERB_PHRASE -> VERB
    VERB_PHRASE -> VERB_PHRASE PREPOSITIONAL_PHRASE
    PREPOSITIONAL_PHRASE -> PREPOSITION NOUN_PHRASE
    DETERMINANT -> 'a'
    DETERMINANT -> 'the'
    NOUN -> 'cat'
    NOUN -> 'dog'
    NOUN -> 'man'
    NOUN -> 'park'
    NOUN -> 'ball'
    NOUN -> 'house'
    NOUN -> 'tree'
    PRONOUN -> 'he'
    PRONOUN -> 'she'
    PRONOUN -> 'it'
    ADJECTIVE -> 'big'
    ADJECTIVE -> 'small'
    ADJECTIVE -> 'happy'
    ADJECTIVE -> 'red'
    ADJECTIVE -> 'old'
    VERB -> 'loves'
    VERB -> 'chases'
    VERB -> 'sees'
    VERB -> 'runs'
    VERB -> 'sleeps'
    VERB -> 'jumps'
    PREPOSITION -> 'in'
    PREPOSITION -> 'with'
    PREPOSITION -> 'near'
    PREPOSITION -> 'under'
    PREPOSITION -> 'on'
```

## Sample Output
Code snippet output for sentence 1. It demonstrates structural ambiguity, where the same sentence can have multiple valid parse trees.
```
--- Sentence 1: the big dog chases a cat in the park ---
Parse successful. Found 2 parse tree(s).

--- Parse Tree 1 ---
                                      SENTENCE                                                                       
                 ┌───────────────────────┴───────────────────────┐                                                    
                 │                                          VERB_PHRASE                                              
                 │                       ┌───────────────────────┴─────────────────────────┐                          
                 │                  VERB_PHRASE                                     PREPOSITIONAL_PH                 
                 │                       │                                                RASE                       
                 │             ┌─────────┴───────────┐                       ┌─────────────┴──────────────┐           
            NOUN_PHRASE        │                NOUN_PHRASE                  │                       NOUN_PHRASE     
     ┌───────────┼───────┐     │         ┌───────────┴───────────┐           │             ┌──────────────┴───────┐   
DETERMINANT  ADJECTIVE  NOUN  VERB  DETERMINANT                 NOUN    PREPOSITION   DETERMINANT                NOUN
     │           │       │     │         │                       │           │             │                      │   
    the         big     dog  chases      a                      cat          in           the                    park

Bracket Notation: (SENTENCE
  (NOUN_PHRASE (DETERMINANT the) (ADJECTIVE big) (NOUN dog))
  (VERB_PHRASE
    (VERB_PHRASE
      (VERB chases)
      (NOUN_PHRASE (DETERMINANT a) (NOUN cat)))
    (PREPOSITIONAL_PHRASE
      (PREPOSITION in)
      (NOUN_PHRASE (DETERMINANT the) (NOUN park)))))

--- Parse Tree 2 ---
                                      SENTENCE                                                                       
                 ┌───────────────────────┴───────────────────────┐                                                    
                 │                                          VERB_PHRASE                                              
                 │             ┌─────────────────────────────────┴───────────┐                                        
                 │             │                                        NOUN_PHRASE                                  
                 │             │                     ┌───────────────────────┴─────────────┐                          
                 │             │                     │                              PREPOSITIONAL_PH                 
                 │             │                     │                                    RASE                       
                 │             │                     │                       ┌─────────────┴──────────────┐           
            NOUN_PHRASE        │                NOUN_PHRASE                  │                       NOUN_PHRASE     
     ┌───────────┼───────┐     │         ┌───────────┴───────────┐           │             ┌──────────────┴───────┐   
DETERMINANT  ADJECTIVE  NOUN  VERB  DETERMINANT                 NOUN    PREPOSITION   DETERMINANT                NOUN
     │           │       │     │         │                       │           │             │                      │   
    the         big     dog  chases      a                      cat          in           the                    park

Bracket Notation: (SENTENCE
  (NOUN_PHRASE (DETERMINANT the) (ADJECTIVE big) (NOUN dog))
  (VERB_PHRASE
    (VERB chases)
    (NOUN_PHRASE
      (NOUN_PHRASE (DETERMINANT a) (NOUN cat))
      (PREPOSITIONAL_PHRASE
        (PREPOSITION in)
        (NOUN_PHRASE (DETERMINANT the) (NOUN park))))))

Ambiguity detected. This sentence has 2 different parse trees.
This sentence demonstrates structural ambiguity in CFGs.
```

### Graphical Parse Tree
This visual window prompt of the parse trees are achieved through the following code snippet:
```python
grammar = nltk.CFG.fromstring("""
    SENTENCE -> NOUN_PHRASE VERB_PHRASE

    NOUN_PHRASE -> PRONOUN
    NOUN_PHRASE -> DETERMINANT NOUN
    NOUN_PHRASE -> DETERMINANT ADJECTIVE NOUN
    NOUN_PHRASE -> NOUN_PHRASE PREPOSITIONAL_PHRASE

    VERB_PHRASE -> VERB NOUN_PHRASE
    VERB_PHRASE -> VERB
    VERB_PHRASE -> VERB_PHRASE PREPOSITIONAL_PHRASE

    PREPOSITIONAL_PHRASE -> PREPOSITION NOUN_PHRASE

    DETERMINANT -> 'a' | 'the'
    NOUN -> 'cat' | 'dog' | 'man' | 'park' | 'ball' | 'house' | 'tree'
    PRONOUN -> 'he' | 'she' | 'it'
    ADJECTIVE -> 'big' | 'small' | 'happy' | 'red' | 'old'
    VERB -> 'loves' | 'chases' | 'sees' | 'runs' | 'sleeps' | 'jumps'
    PREPOSITION -> 'in' | 'with' | 'near' | 'under' | 'on'
""")

sentence = ['the', 'big', 'dog', 'chases', 'a', 'cat', 'in', 'the', 'park']
parser = nltk.ChartParser(grammar)

for tree in parser.parse(sentence):
    tree.draw()
```
<img width="762" height="269" alt="Sentence 1, First Parse Tree" src="https://github.com/user-attachments/assets/8015cbb7-c29a-422e-88c2-1246a3bbce24" />
<img width="761" height="308" alt="Sentence 1, Second Parse Tree" src="https://github.com/user-attachments/assets/96d2fc70-5aff-4889-9f03-7bf3f6b00a7c" />


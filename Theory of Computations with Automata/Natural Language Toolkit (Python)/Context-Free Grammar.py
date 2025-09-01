import nltk
from nltk import TreePrettyPrinter

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

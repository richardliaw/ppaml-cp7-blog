default: compile

preprocessor:
	jupyter nbconvert --to=script preprocessing.ipynb

preprocess_small:
	python3 preprocessing.py Small

preprocess_middle:
	python3 preprocessing.py Middle

preprocess_full:
	python3 preprocessing.py Full

compile:
	cat flu_spread_header.blog \
        flu_spread_model.blog \
        flu_spread_footer.blog > bin/flu_spread_compiled.blog;

	../swift/swift \
         -i bin/flu_spread_compiled.blog \
         -o bin/flu_spread_compiled.cpp \
         -e MHSampler \
         -n 10000000

	g++ -I bin -Ofast -std=c++11 \
		bin/flu_spread_compiled.cpp \
		../swift/src/random/*.cpp \
		-o flu_spread_compiled -larmadillo;

run:
	./flu_spread_compiled > out/output.txt

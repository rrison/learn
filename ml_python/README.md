# system setup
```python
# crete workspace
export ML_PATH="$HOME/ml"
mkdir -p $ML_PATH
pip3 --version
pip3 install --upgrade pip
pip3 install --user --upgrdade virtualenv
pip3 freeze # Output installed packages in requirements format.

# setup virtualenv
cd $ML_PATH
virtualenv env

# activate existing virtualenv
cd $ML_PATH
source env/bin/activate
```

# tips
- ReLU suffers from a problem known as the dying ReLUs. To solve this, use *leaky* ReLU.
- The inverse of **to_categorical** is **np.argmax**

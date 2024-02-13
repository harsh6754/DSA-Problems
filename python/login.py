from flask import Flask, render_template, request, redirect, url_for
from flask_login import LoginManager, UserMixin, login_user, logout_user, login_required
from werkzeug.security import generate_password_hash, check_password_hash


from flask import Flask, render_template

app = Flask(__name__, template_folder='path/to/custom/templates')


app = Flask(__name__)
app.secret_key = 'your_secret_key'

# Login Manager Setup
login_manager = LoginManager()
login_manager.init_app(app)

# Mock User Model
class User(UserMixin):
    def __init__(self, id, username, password):
        self.id = id
        self.username = username
        self.password = password

# Mock Database
users = []

# Routes
@login_manager.user_loader
def load_user(user_id):
    for user in users:
        if user.id == int(user_id):
            return user
    return None

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/login', methods=['GET', 'POST'])
def login():
    if request.method == 'POST':
        username = request.form['username']
        password = request.form['password']

        # Validate user
        for user in users:
            if user.username == username and check_password_hash(user.password, password):
                login_user(user)
                return redirect(url_for('profile'))

        return 'Invalid username or password'

    return render_template('login.html')

@app.route('/signup', methods=['GET', 'POST'])
def signup():
    if request.method == 'POST':
        username = request.form['username']
        password = generate_password_hash(request.form['password'])

        user = User(len(users) + 1, username, password)
        users.append(user)
        return redirect(url_for('login'))

    return render_template('signup.html')

@app.route('/profile')
@login_required
def profile():
    return 'Welcome to your profile'

@app.route('/logout')
@login_required
def logout():
    logout_user()
    return redirect(url_for('index'))

# Image Upload Route
@app.route('/upload', methods=['POST'])
@login_required
def upload():
    if 'file' not in request.files:
        return 'No file part'
    
    file = request.files['file']
    file.save('static/' + file.filename)
    return 'File uploaded successfully'

if __name__ == '__main__':
    app.run(debug=True)

import React, { Component } from 'react';
import { Provider } from 'react-redux';
import { createStore } from 'redux';
import reducer from './reducers/index';
import RootContainer from './components/RootContainer';

const store = createStore(reducer);
class App extends Component {
  render() {
    return (
      <Provider store={store}>
        <RootContainer />
      </Provider>
    );
  }
}

export default App;

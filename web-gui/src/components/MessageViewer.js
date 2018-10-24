import React, { Component } from 'react';
import {connect} from 'react-redux';
import Paper from '@material-ui/core/Paper';
class MessageViewer extends Component {
    styles={
        container:{
            display:'flex',
            flex:2,
            flexDirection: 'column',
            padding: '10px'
        },
        label: {
            alignItems: 'center',
            paddingTop: '5px',
            paddingBottom: '1px',
            marginBottom: '5px',
            paddingRight: '5px',
            borderBottom: '2px solid #4286f4',
            fontSize: '25px',
            borderRadius: '2px',
            fontWeight: '2',
        },
        logContainer:{
            padding:'5px',
            borderRadius: '3px',
            backgroundColor: '#CCCCCC',
        },
        scrollContainer:{
            overflowY: 'scroll',
            height:'600px',
        },
        message:{
            padding: '10px',
        }



    }
  renderMessage =(logIndex)=>{
      if(logIndex==-1){
          return(
            <Paper style={this.styles.message}>
                No log selected.
            </Paper>
          );
      } else{
          return(
            <Paper style={this.styles.message}>
                <code>
                    {this.props.messages[logIndex]}
                </code>
            </Paper>
          )
      }
  }
  render() {
    return (
      <div style={this.styles.container}>
        <div style={this.styles.label}>
            Message Content
        </div>
        <div style={this.styles.logContainer}>
            <div style={this.styles.scrollContainer}>
                {this.renderMessage(this.props.selectedLog)}
            </div>
        </div>
      </div>
    );
  }
}
const mapStateToProps = store => {
    return({
        messages:store.messages,
        selectedLog: store.selectedLog.selectedLog,
    });
}
export default connect(mapStateToProps)(MessageViewer);

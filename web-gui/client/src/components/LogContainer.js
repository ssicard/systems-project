import React, { Component } from 'react';
import { connect } from 'react-redux';
import LogEntry from './LogEntry';
class LogContainer extends Component {
    styles={
        container:{
            display:'flex',
            flex:1.5,
            flexDirection: 'column',
            padding: '10px'
        },
        label: {
            alignItems: 'center',
            paddingTop: '5px',
            marginBottom: '5px',
            paddingRight: '5px',
            paddingBottom: '1px',
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
        }
    }
  renderLogs = ()=>{
        return this.props.logs.map((log,i)=>{
            return(
                <LogEntry log={log} />
            );
        })
  }
  render() {
    return (
      <div style={this.styles.container}>
        <div style={this.styles.label}>
            Logs
        </div>
        <div style={this.styles.logContainer}>
            <div style={this.styles.scrollContainer}>
                {this.renderLogs()}
            </div>       
        </div>
      </div>
    );
  }
}
const mapStateToProps = store => {
    return ({
        logs: store.logs.displayedLogs,
    });
}
export default connect(mapStateToProps)(LogContainer);
